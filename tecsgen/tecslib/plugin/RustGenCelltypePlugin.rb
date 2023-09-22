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
      # @plugin_arg_str = option.gsub( /\A"(.*)/, '\1' )    # 前後の "" を取り除く
      # @plugin_arg_str.sub!( /(.*)"\z/, '\1' )
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
                @use_string_list.push(global_cell_name)
            }
            # すべてのセルタイプ名を mod する．また，受け口を持たないセルタイプは mod しない.
            celltype.get_port_list.each{ |port|
                if port.get_port_type == :ENTRY then
                    global_celltype_name = celltype.get_global_name
                    global_celltype_name = global_celltype_name.to_s
                    global_celltype_name = global_celltype_name[1..-1]
                    global_celltype_name = snake_case(global_celltype_name)
                    file.print "mod client_#{global_celltype_name};\n"
                    @use_string_list.push("client_#{global_celltype_name}")
                else
                end
            }
        }
    end

    def get_sig_param_str sig
        param_list = []
        param_list_diff = []
        param_return = []
        # シグニチャの param_decl を取得する
        # 今回は receive が引数に存在していないからうまくいったが，引数にもしある場合は要素数がずれる．
        sig.each_param{ |func_decl, param_decl|
            case param_decl.get_direction
            when :IN, :INOUT, :OUT
                param_list.push(param_decl)
            when :SEND
                param_list.push(param_decl)
                param_list_diff.push(param_decl.get_size.to_s)
            when :RECEIVE
                # recieve のときは，return として扱うことで，要素をずらさないようにする
                param_list.push("return")
                param_return.push(param_decl)
                param_list_diff.push(param_decl.get_size.to_s)
            end
        }
        # lengthlength2
        # param_list_diff.each{ |diff|
        #     file2.print "#{diff}"
        # }
        # param_decl を文字列にする
        param_list_str =[]
        param_return_str =[]
        param_list.each{ |param_decl|
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
                    param_list_str.push(", #{param_decl.get_name}: mut #{c_type_to_rust_type(param_decl.get_type)}")
                when :RECEIVE
                    param_return_str.push(" -> #{c_type_to_rust_type(param_decl.get_type)}")
                end
            end
        }
        return param_list_str, param_return_str
    end
    
    def gen_use_header file
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
            str = "i#{c_type.get_bit_size}"
        elsif c_type.kind_of?( BoolType ) then
            str = "bool"
        else
            str = "unknown"
        end
        return str
    end

    # セルタイプに受け口がある場合，その受け口につながっているシグニチャを取得する（重複させない)
    # ここでトレイトファイルを生成する
    def gen_namespace_trait_files ns

        ns.get_signature_list.each{ |sig|
            # next if sig.is_allocator? == true
            sig_name = sig.get_global_name.to_s
            file2 = CFile.open( "#{$gen}/#{snake_case(sig_name)}.rs", "w" )
            file2.print <<EOT
pub trait #{camel_case(snake_case(sig_name))}<T> {

EOT
            # シグニチャの引数の文字列を取得する
            param_list_str, param_return_str = get_sig_param_str sig

            sig.get_function_head_array.each{ |func_head|
                return_flag = false
                file2.print "\tfn #{func_head.get_name}(&self, var: &mut T "
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
                if return_flag then
                    temp = param_return_str.shift
                    file2.print ")#{temp};\n\n"
                else
                    file2.print ");\n\n"
                end
            }
            file2.print "}\n"
        }
    end
        
    #=== tCelltype_factory.h に挿入するコードを生成する
    # file 以外の他のファイルにファクトリコードを生成してもよい
    # セルタイププラグインが指定されたセルタイプのみ呼び出される
    def gen_factory file
        if ! @celltype.is_singleton? then

        else

        end
        # トレイトファイルを生成する
        # これは、最初に呼び出されたときに、一度だけ、すべて生成する
        if @@b_signature_header_generated != true then
            @@b_signature_header_generated = true
            ns = Namespace.get_root
            gen_namespace_trait_files ns
        end

        @use_string_list = []

        # そのセルタイプの全てのセルに対して，ファイルを生成する
        @celltype.get_cell_list.each{ |cell|
            if cell.is_generate? then
                global_file_name = cell.get_global_name
                global_file_name = global_file_name.to_s
                # new_string = global_file_name[1..-1]
                global_file_name = snake_case(global_file_name)
            end
            file = CFile.open( "#{$gen}/#{global_file_name}.rs", "w" )

            @use_string_list = []
            # セルタイプに受け口がある場合，use 文を生成する
            @celltype.get_port_list.each{ |port|
                if port.get_port_type == :ENTRY then
                    @use_string_list.push(snake_case(port.get_signature.get_name.to_s))
                    @use_string_list.push("client_#{snake_case(@celltype.get_global_name.to_s[1..-1])}")
                end
            }
            # @use_string_list.uniq!
            
            # 以下の if 文は、最初に呼び出されたときに一度だけ、すべて生成する
            # TODO:将来的にはこの if 文を entry の cell のみに生成する必要がある
            # 現状先頭のセルであるかどうかは，受け口の有無で判断している
            if @@module_generated != true then
                # @@module_generated = true
                gen_module_header file
                # gen_use_header file
            else
                # gen_use_header file
            end

            @use_string_list.uniq!
            gen_use_header file

            # セルタイプに受け口がある場合，構造体の定義と初期化を生成する
            @celltype.get_port_list.each{ |port|
                if port.get_port_type == :ENTRY then
                    cell_name = cell.get_global_name.to_s
                    file.print "pub struct #{cell_name} {\n"
                    @celltype.get_attribute_list.each{ |attr|
                        file.print "\tpub #{attr.get_name}: #{c_type_to_rust_type(attr.get_type)},\n"
                    }
                    file.print "}\n\n"
                    file.print "pub const #{cell_name.upcase}: #{cell_name} = #{cell_name} {\n"
                    @celltype.get_attribute_list.each{ |attr|
                        file.print "\t#{attr.get_name}: #{attr.get_initializer},\n"
                    }
                    file.print "};\n"
                    break
                else
                end
            }
            if @@module_generated != true then
                file.print <<EOT
fn main() {
                                
EOT
            end

            # 結合先のセル名の配列（スネークケース）
            snake_case_call_cell_name = []
            # 結合先のセルタイプ名（キャメルケース）
            camel_case_call_celltype_name = ""
            # 結合先のセル名の配列
            call_cell_name = []

            @celltype.get_port_list.each{ |port|
                if port.get_port_type == :ENTRY then
                else
            # セルタイプに呼び口がある場合，一度だけ呼び出す
                    port2 = port.get_real_callee_port
                    port2_celltype = port2.get_celltype
                    port2_celltype_name = port2_celltype.get_global_name.to_s
                    camel_case_call_celltype_name = camel_case(port2_celltype_name[1..-1])
                # 以下の each は，結合先のセルタイプに関する記述 
                    port2_celltype.get_cell_list.each{ |cell|
                        cell_name = cell.get_global_name.to_s
                        snake_case_call_cell_name.push(snake_case(cell_name))
                        call_cell_name.push(cell_name)
                    }
                    break
                end
            }

            # 結合先のセルタイプのセルの数だけ set 関数で初期化する
            call_cell_name.each_with_index do |call_cell_name, index|
                port_list = @celltype.get_port_list
                if port_list[index].get_port_type == :ENTRY then
                    break
                else
             #     let mut client_print_a = ClientPrint::new_printa_set_cprint(&PRINTA);
                    file.print "\tlet mut client_#{snake_case(call_cell_name)} = Client#{camel_case_call_celltype_name}::new_#{call_cell_name.downcase}_set_#{port_list[index].get_name.downcase}(&#{call_cell_name.upcase});\n"
                end
            end
            
            if @@module_generated != true then
                @@module_generated = true
                file.print <<EOT

}
EOT
            end

            # セルタイプに受け口がある場合，impl を生成する
            # TODO:複数の受け口に異なるシグニチャが設定されている場合，それぞれに対して impl を生成する必要がある
            @celltype.get_port_list.each{ |port|
                if port.get_port_type == :ENTRY then
                    cell_name = cell.get_global_name.to_s
                    sig = port.get_signature
                    signature_name = sig.get_global_name.to_s
                    file.print <<EOT

impl<'a, T> #{camel_case(snake_case(signature_name))}<Client#{camel_case(@celltype.get_global_name.to_s[1..-1])}<'a, T>> for #{cell_name} {

EOT
                    # シグニチャの引数の文字列を取得する
                    param_list_str, param_return_str = get_sig_param_str sig

                    sig.get_function_head_array.each{ |func_head|
                        return_flag = false
                        file.print "\tfn #{func_head.get_name}(&self, var: &mut Client#{camel_case(@celltype.get_global_name.to_s[1..-1])}<T>"
                        param_list_item = func_head.get_paramlist.get_items
                        num = param_list_item.size
                        num.times do
                            temp = param_list_str.shift
                            if temp == "ignore" then
                                next
                            elsif temp == "return" then
                            # TODO: recieve が複数の時にどうするか検討する必要がある
                                return_flag = true
                            else
                                file.print "#{temp}"
                            end
                        end
                        if return_flag then
                            temp = param_return_str.shift
                            file.print ")#{temp}"
                        else
                            file.print ")"
                        end
                        file.print "{\n\n\t}\n\n"
                    }
                    file.print "}"
                else
                end
            }

        } # celltype.get_cell_list.each

        # client_celltype.rs ファイルを生成する
        # セルタイプの呼び口につながっているシグニチャの数だけ生成する
        # TODO:ことなるセルタイプのセルから同一のセルにつながる場合の，set関数の定義を考える必要がある
        # TODO:トレイト関数の引数に関する生成が必要
        # TODO:トレイト関数の返り値に関する生成が必要
        # TODO:返り値があるときの記述に関して，; をつけるかどうかの判断が必要
        @celltype.get_port_list.each{ |port|
            if port.get_port_type == :CALL then
                port2 = port.get_real_callee_port
                port2_celltype = port2.get_celltype
                port2_celltype_name = port2_celltype.get_global_name.to_s
                client_name = "Client#{camel_case(port2_celltype_name[1..-1])}"
                sig_name = snake_case(port.get_signature.get_global_name.to_s)
                if File.exist?("#{$gen}/client_#{snake_case(port2_celltype_name[1..-1])}.rs") then
                else
                    file3 = CFile.open( "#{$gen}/client_#{snake_case(port2_celltype_name[1..-1])}.rs", "w" )
                    file3.print <<EOT
use crate::#{sig_name}::*;

pub struct #{client_name}<'a, T> {
    pub call : Option<&'a, T>,
EOT
                    port2_celltype.get_var_list.each{ |var|
                        file3.print "\tpub #{var.get_name}: #{c_type_to_rust_type(var.get_type)},\n"
                    }
                    file3.print "}\n\n"
                    file3.print <<EOT
impl<'a, T: #{camel_case(sig_name)}<<#{client_name}<'a, T>>> #{client_name}<'a, T> {

EOT
                    port2_celltype.get_cell_list.each{ |cell|
                        file3.print <<EOT
    pub fn new_#{cell.get_global_name.to_s.downcase}_set_#{port.get_name.downcase}(component: &'a T) -> #{client_name}<'a, T> {
        #{client_name} {
            call: Some(component),
EOT
                        port2_celltype.get_var_list.each{ |var|
                            file3.print "\t\t\t#{var.get_name}: #{var.get_initializer},\n"
                        }
                        file3.print "\t\t}\n\t}\n\n"
                    } # port2_celltype.get_cell_list.each

                    # シグニチャの引数の文字列を取得する
                    sig = port.get_signature
                    param_list_str, param_return_str = get_sig_param_str sig

                    actual_param_list_str = []

                    sig.get_function_head_array.each{ |func_head|
                        return_flag = false
                        file3.print "\tpub fn #{func_head.get_name}(&mut self"
                        param_list_item = func_head.get_paramlist.get_items
                        num = param_list_item.size
                        num.times do |i|
                            temp = param_list_str.shift
                            if temp == "ignore" then
                                actual_param_list_str.push("ignore")
                                next
                            elsif temp == "return" then
                                actual_param_list_str.push("return")
                                return_flag = true
                            else
                                file3.print "#{temp}"
                                actual_param_list_str.push(param_list_item[i].get_name.to_s)
                            end
                        end
                        if return_flag then
                            temp = param_return_str.shift
                            file3.print ")#{temp}"
                        else
                            file3.print ")"
                        end

                        file3.print " {\n"
                        file3.print "\t\tself.call.unwrap().#{func_head.get_name}(self"
                        num.times do
                            temp = actual_param_list_str.shift
                            if temp == "ignore" then
                                next
                            elsif temp == "return" then
                                next
                            else
                                file3.print ", #{temp}"
                            end
                        end
                        if return_flag then
                            file3.print ")\n\t}\n\n"
                        else
                            file3.print ");\n\t}\n\n"
                        end

                    } # sig.get_function_head_array.each
                    file3.print "}\n"
                end # if File.exist?("#{$gen}/client_#{snake_case(port2_celltype_name[1..-1])}.rs") then
            end # if port.get_port_type == :CALL then
        } # celltype.get_port_list.each
    end # gen_factory

end
