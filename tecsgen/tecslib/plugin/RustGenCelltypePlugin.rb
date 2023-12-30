# -*- coding: utf-8 -*-
#
#  TECS Generator
#      Generator for TOPPERS Embedded Component System
#  
#   Copyright (C) 2008-2023 by TOPPERS Project
#--
#   上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
#   ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
#   変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
#   (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
#       権表示，この利用条件および下記の無保証規定が，そのままの形でソー
#       スコード中に含まれていること．
#   (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
#       用できる形で再配布する場合には，再配布に伴うドキュメント（利用
#       者マニュアルなど）に，上記の著作権表示，この利用条件および下記
#       の無保証規定を掲載すること．
#   (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
#       用できない形で再配布する場合には，次のいずれかの条件を満たすこ
#       と．
#     (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
#         作権表示，この利用条件および下記の無保証規定を掲載すること．
#     (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
#         報告すること．
#   (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
#       害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
#       また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
#       由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
#       免責すること．
#  
#   本ソフトウェアは，無保証で提供されているものである．上記著作権者お
#   よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
#   に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
#   アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
#   の責任を負わない．
#  
#   $Id: CelltypePlugin.rb 2952 2018-05-07 10:19:07Z okuma-top $
#++

#== celltype プラグインの共通の親クラス
class RustGenCelltypePlugin < CelltypePlugin
    CLASS_NAME_SUFFIX = ""
    @@b_signature_header_generated = false
    @@module_generated = false

    #celltype::     Celltype        セルタイプ（インスタンス）
    def initialize( celltype, option )
      super
      @celltype = celltype
      @plugin_arg_str = option.gsub( /\A"(.*)/, '\1' )    # 前後の "" を取り除く
      @plugin_arg_str.sub!( /(.*)"\z/, '\1' )
      @plugin_arg_str = CDLString.remove_dquote option
      @plugin_arg_list = {}
      @cell_list =[]
    end
  
    #=== 新しいセル
    #cell::        Cell            セル
    #
    # celltype プラグインを指定されたセルタイプのセルが生成された
    # セルタイププラグインに対する新しいセルの報告
    def new_cell( cell )
        @cell_list << cell
    end
    
    #=== 後ろの CDL コードを生成
    #プラグインの後ろの CDL コードを生成
    #file:: File: 
    def self.gen_post_code( file )
      # 複数のプラグインの post_code が一つのファイルに含まれるため、以下のような見出しをつけること
      # file.print "/* '#{self.class.name}' post code */\n"
    end

    # 文字列を snake_case に変換する
    def snake_case(input_string)
        # string = input_string.to_s
        input_string.gsub(/(.)([A-Z])/, '\\1_\\2').downcase
    end

    # 文字列を camelCase に変換する
    def camel_case(input_string)
        input_string.split('_').map(&:capitalize).join
    end

    def gen_module_header file
        # すべてのシグニチャ名を mod する
        Namespace.get_root.get_signature_list.each{ |sig|
            # next if sig.is_allocator? == true
            global_sig_name = sig.get_global_name
            global_sig_name = global_sig_name.to_s
            global_sig_name = snake_case(global_sig_name)
            file.print "mod #{global_sig_name};\n"
        }
        Celltype.get_celltype_list.each{ |celltype|
            # すべてのセルタイプのセル名を mod する．
            celltype.get_cell_list.each{ |cell|
                global_cell_name = cell.get_global_name
                global_cell_name = global_cell_name.to_s
                global_cell_name = snake_case(global_cell_name)
                file.print "mod #{global_cell_name};\n"
                # @use_string_list.push(global_cell_name)
            }
            # すべてのセルタイプ名を mod する．また，受け口を持たないセルタイプは mod しない.
            celltype.get_port_list.each{ |port|
                if port.get_port_type == :ENTRY then
                    global_celltype_name = celltype.get_global_name
                    global_celltype_name = global_celltype_name.to_s
                    global_celltype_name = global_celltype_name[1..-1]
                    global_celltype_name = snake_case(global_celltype_name)
                    file.print "mod client_#{global_celltype_name};\n"
                else
                end
            }
        }
    end

    def get_sig_param_str sig
        param_list = []
        param_list_diff = []
        param_return = []
        lifetime_annotation_flag = false
        # シグニチャの param_decl を取得する
        # 今回は receive が引数に存在していないからうまくいったが，引数にもしある場合は要素数がずれる．
        sig.each_param{ |func_decl, param_decl|
            case param_decl.get_direction
            when :IN, :INOUT, :OUT
                param_list.push(param_decl)
            # send, receive の実装は保留.以下は没版
            # TODO:send, receive の実装
            when :SEND
                param_list.push(param_decl)
                # param_list_diff.push(param_decl.get_size.to_s)
            when :RECEIVE
                param_list.push(param_decl)
                # recieve のときは，return として扱うことで，要素をずらさないようにする
                # param_list.push("return")
                # param_return.push(param_decl)
                # param_list_diff.push(param_decl.get_size.to_s)
            end
        }

        # lengthlength2
        # param_list_diff.each{ |diff|
        #     file2.print "#{diff}"
        # }

        # [out,string(len)]などのlenを削除する
        param_list.each{ |param_decl|
            if param_decl.get_type.kind_of?( PtrType ) && param_decl.get_type.get_string != nil then
                param_list.each_with_index{ |param_decl2, index|
                    if param_decl2.get_name.to_s == param_decl.get_type.get_string.to_s then
                        param_list.delete_at(index)
                    end
                }
            end
        }

        # param_decl を文字列にする
        param_list_str =[]
        param_return_str =[]
        param_list.each{ |param_decl|
            param_type = param_decl.get_type.get_type_str
            if check_lifetime_annotation(param_type) then
                lifetime_annotation_flag = true
            end
            if param_decl == "return" then
                next
            elsif param_list_diff.include?(param_decl.get_name.to_s) then
                param_list_str.push("ignore")
            else
                # file2.print "#{param_decl.get_name} "
                case param_decl.get_direction
                when :IN
                    param_list_str.push(", #{param_decl.get_name}: &#{c_type_to_rust_type(param_decl.get_type)}")
                when :INOUT
                    param_list_str.push(", #{param_decl.get_name}: &mut #{c_type_to_rust_type(param_decl.get_type)}")
                when :OUT
                    param_list_str.push(", #{param_decl.get_name}: &mut #{c_type_to_rust_type(param_decl.get_type)}")
                when :SEND
                    param_list_str.push("ignore")
                    # param_list_str.push(", #{param_decl.get_name}: mut #{c_type_to_rust_type(param_decl.get_type)}")
                when :RECEIVE
                    param_list_str.push("ignore")
                    # param_return_str.push(" -> #{c_type_to_rust_type(param_decl.get_type)}")
                end
            end
        }
        return param_list_str, param_return_str, lifetime_annotation_flag
    end

    # 正規表現を用いて，Option 型などに変換する
    def convert_rust_type_string(input)
        # 正規表現パターンの配列を定義
        patterns = [
          /Option__(\w+)__/,
          /Option_Ref__(\w+)__/,
          /Option_Ref_mut__(\w+)__/,
          /Option_Ref_a_mut__(\w+)__/,
          /Ref__(\w+)__/,
          /Ref_mut__(\w+)__/,
          /Ref_a__(\w+)__/,
          # 他にも必要なパターンがあれば追加
        ]
      
        # 各パターンに対する変換ロジックを定義
        conversion_rules = {
          0 => lambda { |type_name| "Option<#{type_name}>" },
          1 => lambda { |type_name| "Option<& #{type_name}>" },
          2 => lambda { |type_name| "Option<&mut #{type_name}>" },
          3 => lambda { |type_name| "Option<&'a mut #{type_name}>" },
          4 => lambda { |type_name| "&#{type_name}" },
          5 => lambda { |type_name| "&mut #{type_name}" },
          6 => lambda { |type_name| "&'a #{type_name}" },
          # 他にも必要な変換ルールがあれば追加
        }
      
        # 各パターンに対して処理を行う
        result = input.dup
        patterns.each_with_index do |pattern, index|
          result.gsub!(pattern) do |match|
            type_name = $1
            conversion_rules[index].call(type_name)
          end
        end
      
        return result
    end
    
    # 正規表現のパターンを用いて，ライフタイムが必要かチェックする関数
    # 正規表現のパターン以外には対応していない
    def check_lifetime_annotation str
        # 正規表現パターンの配列を定義
        patterns = [
            /Option_Ref_a_mut__(\w+)__/,
            /Ref_a__(\w+)__/,
            # 他にも必要なパターンがあれば追加
        ]

        # 各正規表現パターンとの一致を確認
        match_found = patterns.any? { |pattern| str =~ pattern }

        return match_found

    end

    # @use_string_list に格納されている文字列を元に use 文を生成する
    def gen_use_header file
        if @celltype.get_var_list.length != 0 then
            file.print "use spin::Mutex;\n"
            # file.print "use crate::kernel_obj_ref::*;\n"
        end
        file.print "use crate::{"
        @use_string_list.each{ |use_string|
            if use_string != @use_string_list.last then
                file.print "#{use_string}::*, "
            else
                file.print "#{use_string}::*};\n\n"
            end
        }
        # @use_string_list = []
    end
    # 宣言されている型を Rust の型に変換する
    # 現状として，int8_t, int16_t, int32_t, int64_t のみ対応
    # TODO:他の型への対応
    def c_type_to_rust_type c_type
        
        if c_type.kind_of?( IntType ) then
            # TODO: ここで符号付きかどうかを判断する
            if c_type.get_sign == :SIGNED then
                str = "i#{c_type.get_bit_size}"
            elsif c_type.get_sign == :UNSIGNED then
                str = "u#{c_type.get_bit_size}"
            else
                str = "i#{c_type.get_bit_size}"
            end
        elsif c_type.kind_of?( BoolType ) then
            str = "bool"
        elsif c_type.kind_of?( FloatType ) then
            str = "f#{c_type.get_bit_size}"
        elsif c_type.kind_of?( ArrayType ) then
            type = c_type_to_rust_type(c_type.get_type)
            subscript = c_type.get_subscript
            str = "[#{type}; #{subscript}]"
        elsif c_type.kind_of?( PtrType ) then
            if c_type.get_string != nil then
                # str = "#{c_type.has_sized_pointer?}"
                # str = "#{c_type.get_max}"
                # [out,string(len)]の場合は，ここでlenが返ってくる
                # [out,string(256)]の場合は，256が返ってくる
                # [in, string]の場合は，-1が返ってくる
                # str = "#{c_type.get_string}"
                # c_type.get_stringが数字かどうかを判断する
                if c_type.get_string.to_s.match?(/^\d+$/)
                    string = c_type.get_string.to_s.to_i
                    if string <= 0 then
                        string = 256
                    end
                else
                    string = 256
                end

                str = "heapless::String<#{string}>"

                if c_type.get_size != nil then
                    size = c_type.get_size.to_s.to_i
                    str.prepend("heapless::Vec::<")
                    str.concat(", #{size}>")
                end
            elsif c_type.get_size != nil then
                # TODO: size_is指定子のときの処理
                type = c_type_to_rust_type(c_type.get_type)
                str = "[#{type}; #{c_type.get_size}]"
            elsif c_type.get_count != nil then
                type = c_type_to_rust_type(c_type.get_type)
                str = "[#{type}; #{c_type.get_size}]"
            elsif c_type.get_max != nil then
                str = "check_max"
            else
                # ポインタの中の型に対して，もう一度 c_type_to_rust_type を呼び出す
                type = c_type_to_rust_type(c_type.get_type)
                str = type.gsub("*", "")
                str = convert_rust_type_string(str)
                if str == "void" then
                    str = "unknown"
                end
            end
        else
            str = c_type.get_type_str
            str = convert_rust_type_string(str)
            if str == "void" then
                str = "unknown"
            end
        end
        # print "c_type_to_rust_type: #{str}\n"
        return str
    end

    # implファイルにuse文を生成する
    def gen_use_for_trait_files file, celltype, port
        if @celltype.get_var_list.length != 0 then
            file.print "use spin::Mutex;\n"
        end
    end

    # セルタイプに呼び口がある場合，その呼び口につながっているシグニチャのトレイトファイルを生成する
    def gen_trait_files

        @celltype.get_port_list.each{ |port|
            # if port.get_port_type == :CALL then

                sig = port.get_signature
                sig_name = sig.get_global_name.to_s

                gen_mod_in_main_lib_rs_for_signature sig
                # if File.exist?("#{$gen}/#{snake_case(sig_name)}.rs") then
                #     return
                # else
                    file2 = CFile.open( "#{$gen}/#{snake_case(sig_name)}.rs", "w" )
                # end

                gen_use_for_trait_files file2, @celltype, port

                file2.print "pub trait #{camel_case(snake_case(sig_name))} {\n"
                # シグニチャの引数の文字列を取得する
                param_list_str, param_return_str, lifetime_flag = get_sig_param_str sig

                sig.get_function_head_array.each{ |func_head|
                    return_flag = false
                    file2.print "\t#[inline]\n"
                    file2.print "\tfn #{func_head.get_name}"
                    if lifetime_flag then
                        file2.print("<'a>")
                    end
                    file2.print "(&self"
                    param_list_item = func_head.get_paramlist.get_items
                    num = param_list_item.size
                    num.times do
                        temp = param_list_str.shift
                        if temp == "ignore" then
                            next
                        elsif temp == "return" then
                            return_flag = true
                        else
                            file2.print "#{temp}"
                        end
                    end
                    # if return_flag then
                    #     temp = param_return_str.shift
                    #     file2.print ")#{temp};\n\n"
                    # else
                    #     file2.print ");\n\n"
                    # end
                    file2.print ")"

                    # 返り値の型がunknown,つまりvoidのときは，-> を生成しない
                    if c_type_to_rust_type(func_head.get_return_type) != "unknown" then
                        file2.print "-> #{c_type_to_rust_type(func_head.get_return_type)}"
                    end

                    file2.print ";\n"

                }
                file2.print "}\n"

            # end
        }


    end

    def gen_mod_in_main_lib_rs_for_cell cell
        plugin_option = @plugin_arg_str.strip
        if plugin_option == "main" || plugin_option == "lib" then
            tempfile = CFile.open( "#{$gen}/#{plugin_option}.rs", "a" )
            tempfile.print "mod #{snake_case(cell.get_global_name.to_s)};\n"
            @celltype.get_port_list.each{ |port|
                if port.get_port_type == :ENTRY then
                    tempfile.print "mod #{snake_case(cell.get_global_name.to_s)}_impl;\n"
                    break
                end
            }
            tempfile.close
            lines = File.readlines("#{$gen}/#{plugin_option}.rs", chomp: true).uniq!
            if lines != nil then
                File.open("#{$gen}/#{plugin_option}.rs", 'w') do |file|
                    lines.each { |line| file.puts line }
                end
            end
        end
    end

    def gen_mod_in_main_lib_rs_for_signature signature
        plugin_option = @plugin_arg_str.strip
        if plugin_option == "main" || plugin_option == "lib" then
            tempfile = CFile.open( "#{$gen}/#{plugin_option}.rs", "a" )
            tempfile.print "mod #{snake_case(signature.get_global_name.to_s)};\n"
            tempfile.close
            lines = File.readlines("#{$gen}/#{plugin_option}.rs", chomp: true).uniq!
            if lines != nil then
                File.open("#{$gen}/#{plugin_option}.rs", 'w') do |file|
                    lines.each { |line| file.puts line }
                end
            end
        end
    end

    # セルタイプに受け口がある場合，その受け口につながっているシグニチャなどを @use_string_list に追加する
    def get_use_for_entry_port file
        # @use_string_list.push("kernel_obj_ref")
        # セルタイプに受け口がある場合，use 文を生成する
        @celltype.get_port_list.each{ |port|
            # if port.get_real_callee_cell != nil then
                @use_string_list.push(snake_case(port.get_signature.get_global_name.to_s))
                if port.get_port_type == :ENTRY then
                    # @use_string_list.push("#{snake_case(@celltype.get_global_name.to_s[1..-1])}_des")
                else
                    call_celltype_name = port.get_real_callee_port.get_celltype.get_global_name.to_s
                    call_cell_name = port.get_real_callee_cell.get_global_name.to_s
                    @use_string_list.push("#{snake_case(call_cell_name)}")
                    # @use_string_list.push("#{snake_case(call_celltype_name[1..-1])}_des")
                end
            # end
        }
    end

    # そのセルタイプの呼び口のリストを取得する
    def get_callport_list
        callport_list = []
        @celltype.get_port_list.each{ |port|
            if port.get_port_type == :CALL then
                callport_list.push(port)
            end
        }
        return callport_list
    end

    # ジェネリクスに使うアルファベットのリストを生成
    def get_jenerics_alphabet_list callport_list
        jenerics_alphabet = ('T'..'Z').to_a + ('A'..'S').to_a
        use_jenerics_alphabet = []
        if callport_list.length != 0 then
            use_jenerics_alphabet = jenerics_alphabet[0..callport_list.length-1]
        end
        return use_jenerics_alphabet
    end

    # セルの構造体の定義の先頭部を生成
    def gen_rust_cell_structure_header file, cell, callport_list, use_jenerics_alphabet
        file.print "pub struct #{camel_case(snake_case(cell.get_global_name.to_s))}"
        if check_empty_celltype @celltype then
        else
            file.print "<'a"
            callport_list.zip(use_jenerics_alphabet).each do |callport, alphabet|
                file.print ", #{alphabet}"
            end
            file.print ">"
        end
        file.print "\n"
    end

    # セル構造体のジェネリクスの where 句を生成
    def gen_rust_cell_structure_jenerics file, cell, callport_list, use_jenerics_alphabet
        where_flag = true
        callport_list.zip(use_jenerics_alphabet).each do |callport, alphabet|
            if where_flag then
                file.print "where\n"
                where_flag = false
            end
            file.print "\t#{alphabet}: #{camel_case(snake_case(callport.get_signature.get_global_name.to_s))},\n"
        end
    end

    # セル構造体の呼び口フィールドの定義を生成
    def gen_rust_cell_structure_callport file, cell, callport_list, use_jenerics_alphabet
        callport_list.zip(use_jenerics_alphabet).each do |callport, alphabet|
            file.print "\tpub #{snake_case(callport.get_name.to_s)}: &'a #{alphabet},\n"
        end
    end

    # セル構造体の属性フィールドの定義を生成
    def gen_rust_cell_structure_attribute file, cell, callport_list, use_jenerics_alphabet
        @celltype.get_attribute_list.each{ |attr|
            if attr.is_omit? then
                next
            else
                file.print "\tpub #{attr.get_name.to_s}: "
                # file.print "#{c_type_to_rust_type(attr.get_type)}"
                str = c_type_to_rust_type(attr.get_type)
                file.print "#{str},\n"
            end
        }
    end

    # セル構造体の変数フィールドの定義を生成
    def gen_rust_cell_structure_variable file, cell
        if @celltype.get_var_list.length != 0 then
            file.print "\tpub variable: &'a Mutex<#{camel_case(snake_case(cell.get_global_name.to_s))}Var"
            # ライフタイムアノテーションの生成部
            # TODO：ライフタイムについては，もう少し厳格にする必要がある
            @celltype.get_var_list.each{ |var|
                var_type_name = var.get_type.get_type_str
                if check_lifetime_annotation var_type_name then
                    file.print "<'a>"
                    break
                end
            }
            file.print ">,\n"
        end
    end

    # 変数構造体の定義を生成
    def gen_rust_variable_structure file, cell
        if @celltype.get_var_list.length != 0 then
            file.print "pub struct #{camel_case(snake_case(cell.get_global_name.to_s))}Var" 
            # ライフタイムアノテーションの生成部
            # TODO：ライフタイムについては，もう少し厳格にする必要がある
            @celltype.get_var_list.each{ |var|
                var_type_name = var.get_type.get_type_str
                if check_lifetime_annotation var_type_name then
                    file.print "<'a>"
                    break
                end
            }
            file.print "{\n"

            # 変数構造体のフィールドの定義を生成
            @celltype.get_var_list.each{ |var|
                file.print "\tpub #{var.get_name}: #{c_type_to_rust_type(var.get_type)},\n"
            }

            file.print "}\n\n"
        end
    end

    # セルの構造体の初期化の先頭部を生成
    def gen_rust_cell_structure_header_initialize file, cell
        file.print "pub static #{cell.get_global_name.to_s.upcase}: #{camel_case(snake_case(cell.get_global_name.to_s))}"
    end

    # セル構造体のジェネリクス代入部を生成
    def gen_rust_cell_structure_jenerics_initialize file, cell, callport_list, use_jenerics_alphabet
        jenerics_flag = true
        # ジェネリクスを代入
        callport_list.each_with_index do |callport, index|
            if jenerics_flag then
                file.print "<"
                jenerics_flag = false
            end
            entryport_name = camel_case(snake_case(callport.get_real_callee_port.get_name.to_s))
            callee_cell_name = camel_case(snake_case(callport.get_real_callee_cell.get_global_name.to_s))
            if index == callport_list.length - 1
            # 最後の要素の処理
                file.print "#{entryport_name}For#{callee_cell_name}>"
            else
            # 通常の要素の処理
                file.print "#{entryport_name}For#{callee_cell_name}, "
            end
        end # port_list.each_with_index
        file.print " = #{camel_case(snake_case(cell.get_global_name.to_s))} "
    end

    # セルの構造体の呼び口フィールドの初期化を生成
    def gen_rust_cell_structure_callport_initialize file, cell, callport_list, use_jenerics_alphabet
        @celltype.get_port_list.each{ |port|
            if port.get_port_type == :CALL then
                entryport_name = camel_case(snake_case(port.get_real_callee_port.get_name.to_s))
                call_cell_name = port.get_real_callee_cell.get_global_name.to_s
                file.print "\t#{snake_case(port.get_name.to_s)}: &#{entryport_name.upcase}FOR#{call_cell_name.upcase},\n"
            end
        }
    end

    # セルの構造体の属性フィールドの初期化を生成
    def gen_rust_cell_structure_attribute_initialize file, cell
        @celltype.get_attribute_list.each{ |attr|
            if attr.is_omit? then
            else
                # セル記述で初期化されていても，反映する
                attr_symbol = attr.get_name.to_s.to_sym
                attr_array = cell.get_attr_initializer(attr_symbol)
                # 属性が配列であるときに対応
                if attr_array.is_a?(Array) then
                    file.print "\t#{attr.get_name.to_s}: ["
                    attr_array.each{ |attr_array_item|
                        if attr_array_item == attr_array.last then
                            file.print "#{attr_array_item}"
                        else
                            file.print "#{attr_array_item}, "
                        end
                    }
                    file.print "],\n"
                else
                    file.print "\t#{attr.get_name.to_s}: #{cell.get_attr_initializer(attr_symbol).to_s},\n"
                end
            end
        }
    end

    # セルの構造体の変数フィールドの初期化を生成
    def gen_rust_cell_structure_variable_initialize file, cell
        if @celltype.get_var_list.length != 0 then
            file.print "\tvariable: &#{cell.get_global_name.to_s.upcase}VAR,\n"
        end
    end

    # 変数構造体の初期化を生成
    def gen_rust_variable_structure_initialize file, cell
        if @celltype.get_var_list.length != 0 then
            file.print "pub static #{cell.get_global_name.to_s.upcase}VAR: Mutex<#{camel_case(snake_case(cell.get_global_name.to_s))}Var> = Mutex::new(#{camel_case(snake_case(cell.get_global_name.to_s))}Var {\n"

            # 変数構造体のフィールドの初期化を生成
            @celltype.get_var_list.each{ |var|
                var_array = var.get_initializer
                # 属性が配列であるときに対応
                if var_array.is_a?(Array) then
                    file.print "\t#{var.get_name}: ["
                    var_array.each{ |var_array_item|
                        if var_array_item == var_array.last then
                            file.print "#{var_array_item.to_s}"
                        else
                            file.print "#{var_array_item.to_s}, "
                        end
                    }
                    file.print "],\n"
                else
                    file.print "\t#{var.get_name}: #{var.get_initializer},\n"
                end
            }

            file.print "});\n\n"

        end
    end

    # 受け口構造体の定義と初期化を生成
    def gen_rust_entry_structure file, cell, callport_list, use_jenerics_alphabet
        @celltype.get_port_list.each{ |port|
            if port.get_port_type == :ENTRY then
                # 受け口構造体の定義を生成
                file.print"pub struct #{camel_case(snake_case(port.get_name.to_s))}For#{camel_case(snake_case(cell.get_global_name.to_s))}"
                file.print "<'a>"
                file.print "{\n"
                @celltype.get_cell_list.each{ |cell|
                    # 受け口を持っているセルの参照をフィールドとして生成
                    file.print "\tpub cell: &'a #{camel_case(snake_case(cell.get_global_name.to_s))}"
                    if check_empty_celltype @celltype then
                    else
                        file.print "<'a"
                        @celltype.get_port_list.each{ |port|
                            # ジェネリクスの代入を生成
                            if port.get_port_type == :CALL then
                                entryport_name = camel_case(snake_case(port.get_real_callee_port.get_name.to_s))
                                call_cell_name = camel_case(snake_case(port.get_real_callee_cell.get_global_name.to_s))
                                file.print ", #{entryport_name}For#{call_cell_name}<'a>"
                            end
                        }
                        file.print ">"
                    end
                    file.print ",\n"
                }
                file.print "}\n\n"

                # 受け口構造体の初期化を生成
                # 一つの受け口構造体がもつセルは１つ
                file.print "pub static #{port.get_name.to_s.upcase}FOR#{cell.get_global_name.to_s.upcase}: #{camel_case(snake_case(port.get_name.to_s))}For#{camel_case(snake_case(cell.get_global_name.to_s))} = #{camel_case(snake_case(port.get_name.to_s))}For#{camel_case(snake_case(cell.get_global_name.to_s))} {\n"
                @celltype.get_cell_list.each{ |cell|
                    file.print "\tcell: &#{cell.get_global_name.to_s.upcase},\n"
                }
                file.print "};\n\n"
                
            end
        }
    end

    # セルタイプに受け口がある場合，受け口関数を生成する
    def gen_rust_entryport_function file, cell, callport_list, use_jenerics_alphabet
        # セルタイプに受け口がある場合，impl を生成する
        @celltype.get_port_list.each{ |port|
            if port.get_port_type == :ENTRY then
                cell_name = cell.get_global_name.to_s
                sig = port.get_signature
                signature_name = sig.get_global_name.to_s

                file.print "impl #{camel_case(snake_case(port.get_signature.get_global_name.to_s))} for #{camel_case(snake_case(port.get_name.to_s))}For#{camel_case(snake_case(cell.get_global_name.to_s))}<'_"

                # # if callport_list.length != 0 then
                # #     file.print ", "
                # # end

                # 以下のジェネリクス代入部は要らない可能性あり
                # # ジェネリクスを代入
                # callport_list.each_with_index do |callport, index|
                #     if check_callee_port_celltype_is_itron_object callport then
                #         entryport_name = camel_case(snake_case(callport.get_real_callee_port.get_name.to_s))
                #         call_cell_name = camel_case(snake_case(callport.get_real_callee_cell.get_global_name.to_s))
                #         if index == callport_list.length - 1
                #             # 最後の要素の処理
                #             file.print ", #{entryport_name}For#{call_cell_name}"
                #         else
                #             # 通常の要素の処理
                #             file.print ", #{entryport_name}For#{call_cell_name}"
                #         end
                #         # next
                #     else
                #         entryport_name = camel_case(snake_case(callport.get_real_callee_port.get_name.to_s))
                #         call_cell_name = camel_case(snake_case(callport.get_real_callee_cell.get_global_name.to_s))
                #         callee_cell = callport.get_real_callee_cell
                #         callee_celltype = callee_cell.get_celltype
                #         if index == callport_list.length - 1
                #             # 最後の要素の処理
                #             file.print ", #{entryport_name}For#{call_cell_name}"
                #             callee_celltype.get_port_list.each do |callee_port|
                #                 if callee_port.get_port_type == :CALL then
                #                     file.print "<'_>"
                #                     break
                #                 end
                #             end
                #         else
                #             # 通常の要素の処理
                #             file.print ", #{entryport_name}For#{call_cell_name}"
                #             callee_celltype.get_port_list.each do |callee_port|
                #                 if callee_port.get_port_type == :CALL then
                #                     file.print "<'_>"
                #                 end
                #             end
                #         end
                #     end
                # end # port_list.each_with_index

                file.print ">"
                
                file.print "{\n\n"

                sig_param_str_list, _, lifetime_flag = get_sig_param_str sig

                # 空の関数を生成
                sig.get_function_head_array.each{ |func_head|
                    # 関数のインライン化
                    file.print "\t#[inline]\n"
                    file.print "\tfn #{func_head.get_name}"
                    if lifetime_flag then
                        file.print "<'a>"
                    end
                    file.print"(&self"
                    param_num = func_head.get_paramlist.get_items.size
                    param_num.times do
                        temp = sig_param_str_list.shift
                        if temp == "ignore" then
                            next
                        end
                        file.print "#{temp}"
                    end
                    file.print ") "

                    # 返り値の型がunknown,つまりvoidのときは，-> を生成しない
                    if c_type_to_rust_type(func_head.get_return_type) != "unknown" then
                        file.print "-> #{c_type_to_rust_type(func_head.get_return_type)}"
                    end

                    file.print "{\n"

                    # get_cell_ref 関数の呼び出しを生成
                    file.print "\t\tlet cell_ref = self.cell.get_cell_ref();\n\n"

                    file.print"\t}\n"
                }

                file.print "}\n\n"

            else
            end
        }
    end
    # セルタイプに受け口以外の要素があるかどうかを判断する
    def check_empty_celltype celltype
        celltype.get_port_list.each{ |port|
            if port.get_port_type == :CALL then
                return false
            end
        }
        if celltype.get_attribute_list.length != 0 then
            return false
        end
        if celltype.get_var_list.length != 0 then
            return false
        end
        return true
    end

    # get_cell_ref 関数を生成する
    def gen_rust_get_cell_ref file, cell, callport_list, use_jenerics_alphabet
        # セルタイプに受け口がない場合は，生成しない
        # 受け口がないならば，get_cell_ref 関数が呼ばれることは現状無いため
        @celltype.get_port_list.each{ |port|
            if port.get_port_type == :ENTRY then
                jenerics_flag = true
                file.print "impl"
                if check_empty_celltype @celltype then
                else
                    file.print "<"
                end
                # ライフタイムアノテーションの生成部
                # TODO：ライフタイムについては，もう少し厳格にする必要がある
                @celltype.get_var_list.each{ |var|
                    var_type_name = var.get_type.get_type_str
                    if check_lifetime_annotation var_type_name then
                        file.print "'a, "
                        break
                    end
                }
                # impl のジェネリクスを生成
                callport_list.zip(use_jenerics_alphabet).each do |callport, alphabet|
                    if jenerics_flag then
                        jenerics_flag = false
                        file.print "#{alphabet}: #{camel_case(snake_case(callport.get_signature.get_global_name.to_s))}"
                    else
                        file.print ", #{alphabet}: #{camel_case(snake_case(callport.get_signature.get_global_name.to_s))}"
                    end
                end
                if check_empty_celltype @celltype then
                else
                    file.print ">"
                end

                # impl する型を生成
                file.print " #{camel_case(snake_case(cell.get_global_name.to_s))}"
                if check_empty_celltype @celltype then
                else
                    file.print "<'"
                    # ライフタイムアノテーションの生成部
                    # TODO：ライフタイムについては，もう少し厳格にする必要がある
                    if @celltype.get_var_list.length != 0 then
                        @celltype.get_var_list.each{ |var|
                            var_type_name = var.get_type.get_type_str
                            if check_lifetime_annotation var_type_name then
                                file.print "a"
                                break
                            else
                                file.print "_"
                                break
                            end
                        }
                    else
                        file.print "_"
                    end
                    callport_list.zip(use_jenerics_alphabet).each do |callport, alphabet|
                        file.print ", #{alphabet}"
                    end
                    file.print ">"
                end
                file.print " {\n"
                # インライン化
                file.print "\t#[inline]\n"
                # get_cell_ref 関数の定義を生成
                file.print "\tpub fn get_cell_ref"
                # ライフタイムアノテーションの生成部
                # TODO：ライフタイムについては，もう少し厳格にする必要がある
                @celltype.get_var_list.each{ |var|
                    var_type_name = var.get_type.get_type_str
                    if check_lifetime_annotation var_type_name then
                        file.print "<'a>"
                        break
                    end
                }
                file.print "(&self) -> ("
                # 返り値のタプル型の定義を生成
                callport_list.zip(use_jenerics_alphabet).each_with_index do |(callport, alphabet), index|
                    if index == 0 then
                        file.print "&#{alphabet}"
                    else
                        file.print ", &#{alphabet}"
                    end
                end
                @celltype.get_attribute_list.each{ |attr|
                    if attr.is_omit? then
                        next
                    end
                    if callport_list.length == 0 then
                        file.print "&#{c_type_to_rust_type(attr.get_type)}"
                    else
                        file.print ", &#{c_type_to_rust_type(attr.get_type)}"
                    end
                }

                if @celltype.get_var_list.length != 0 then
                    if callport_list.length == 0 && @celltype.get_attribute_list.length == 0 then
                        file.print "&Mutex<#{camel_case(snake_case(cell.get_global_name.to_s))}Var"
                        # ライフタイムアノテーションの生成部
                        # TODO：ライフタイムについては，もう少し厳格にする必要がある
                        @celltype.get_var_list.each{ |var|
                            var_type_name = var.get_type.get_type_str
                            if check_lifetime_annotation var_type_name then
                                file.print "<'a>"
                                break
                            end
                        }
                        file.print ">) {\n"
                    else
                        file.print ", &Mutex<#{camel_case(snake_case(cell.get_global_name.to_s))}Var"
                        # ライフタイムアノテーションの生成部
                        # TODO：ライフタイムについては，もう少し厳格にする必要がある
                        @celltype.get_var_list.each{ |var|
                            var_type_name = var.get_type.get_type_str
                            if check_lifetime_annotation var_type_name then
                                file.print "<'a>"
                                break
                            end
                        }
                        file.print ">) {\n"
                    end
                else
                    file.print ") {\n"
                end

                # 返り値のタプル型を生成
                file.print "\t\t("
                callport_list.each_with_index do |callport, index|
                    if index == 0 then
                        file.print "&self.#{snake_case(callport.get_name.to_s)}"
                    else
                        file.print ", &self.#{snake_case(callport.get_name.to_s)}"
                    end
                end
                @celltype.get_attribute_list.each{ |attr|
                    if attr.is_omit? then
                        next
                    end
                    if callport_list.length == 0 then
                        file.print "&self.#{attr.get_name.to_s}"
                    else
                        file.print ", &self.#{attr.get_name.to_s}"
                    end
                }
                if @celltype.get_var_list.length != 0 then
                    if callport_list.length == 0 && @celltype.get_attribute_list.length == 0 then
                        file.print "&self.variable)\n\t}\n}\n\n"
                    else
                        file.print ", self.variable)\n\t}\n}\n\n"
                    end
                else
                    file.print ")\n\t}\n}\n\n"
                end
                # get_cell_ref 関数を生成するのは1回だけでいいため，break する
                break

            end # if port.get_port_type == :ENTRY then
        } # celltype.get_port_list.each
    end

    # implファイルのuse文を生成する
    def gen_use_for_impl_file file, cell
        use_list = []
        use_list.push("#{snake_case(cell.get_global_name.to_s)}")
        @celltype.get_port_list.each{ |port|
            use_list.push("#{snake_case(port.get_signature.get_global_name.to_s)}")
        }
        use_list.uniq!
        if @celltype.get_var_list.length != 0 then
            file.print "use spin::Mutex;\n"
        end
        file.print "use crate::{"
        use_list.each{ |use_str|
            if use_str == use_list.last then
                file.print "#{use_str}::*"
            else
                file.print "#{use_str}::*, "
            end
        }
        file.print "};\n\n"
    end
    
    #=== tCelltype_factory.h に挿入するコードを生成する
    # file 以外の他のファイルにファクトリコードを生成してもよい
    # セルタイププラグインが指定されたセルタイプのみ呼び出される
    def gen_factory file
        if ! @celltype.is_singleton? then

        else

        end

        
        # 最初に呼び出されたときに、一度だけ、生成するファイル
        if @@b_signature_header_generated != true then
            @@b_signature_header_generated = true
        end

        @use_string_list = []

        # そのセルタイプの全てのセルに対して，ファイルを生成する
        @celltype.get_cell_list.each{ |cell|
            if cell.is_generate? then
                # lib.rs に mod を追加する
                global_file_name = cell.get_global_name
                global_file_name = global_file_name.to_s
                # new_string = global_file_name[1..-1]
                global_file_name = snake_case(global_file_name)
            end

            gen_mod_in_main_lib_rs_for_cell cell

            # gen_mod_test cell

            file = CFile.open( "#{$gen}/#{global_file_name}.rs", "w" )

            @use_string_list = []

            # セルタイプに受け口がある場合，use 文を生成する
            get_use_for_entry_port file

            @use_string_list.uniq!
            gen_use_header file

            # そのセルタイプの呼び口のリストを取得する
            callport_list = get_callport_list

            # ジェネリクスに使うアルファベットのリストを生成
            use_jenerics_alphabet = get_jenerics_alphabet_list callport_list

            # セルの構造体の定義の先頭部を生成
            gen_rust_cell_structure_header file, cell, callport_list, use_jenerics_alphabet


            # セル構造体のジェネリクスの where 句を生成
            gen_rust_cell_structure_jenerics file, cell, callport_list, use_jenerics_alphabet
            
            file.print "{\n"

            # セル構造体の呼び口フィールドの定義を生成
            gen_rust_cell_structure_callport file, cell, callport_list, use_jenerics_alphabet

            # セル構造体の属性フィールドの定義を生成
            gen_rust_cell_structure_attribute file, cell, callport_list, use_jenerics_alphabet

            # セル構造体の変数フィールドの定義を生成
            gen_rust_cell_structure_variable file, cell

            file.print "}\n\n"

            # 変数構造体の定義を生成
            gen_rust_variable_structure file, cell

            # セルの構造体の初期化の先頭部を生成
            gen_rust_cell_structure_header_initialize file, cell

            # セル構造体の初期化ためのジェネリクス代入部を生成
            gen_rust_cell_structure_jenerics_initialize file, cell, callport_list, use_jenerics_alphabet

            file.print "{\n"

            # セルの構造体の呼び口フィールドの初期化を生成
            gen_rust_cell_structure_callport_initialize file, cell, callport_list, use_jenerics_alphabet

            # セルの構造体の属性フィールドの初期化を生成
            gen_rust_cell_structure_attribute_initialize file, cell

            # セルの構造体の変数フィールドの初期化を生成
            gen_rust_cell_structure_variable_initialize file, cell

            file.print "};\n\n"

            # 変数構造体の初期化を生成
            gen_rust_variable_structure_initialize file, cell

            # 受け口構造体の定義と初期化を生成
            gen_rust_entry_structure file, cell, callport_list, use_jenerics_alphabet

            # get_cell_ref 関数を生成する
            gen_rust_get_cell_ref file, cell, callport_list, use_jenerics_alphabet

            file.close

            file = CFile.open( "#{$gen}/#{global_file_name}_impl.rs", "w" )

            # implファイルようのuse文を生成
            gen_use_for_impl_file file, cell

            # セルタイプに受け口がある場合，impl を生成する
            gen_rust_entryport_function file, cell, callport_list, use_jenerics_alphabet

        } # celltype.get_cell_list.each

        # トレイトファイルを生成する
        # これは，各セルタイプの呼び口につながっているシグニチャに対してのみ，トレイトファイルを生成する
        gen_trait_files

    end # gen_factory

end
