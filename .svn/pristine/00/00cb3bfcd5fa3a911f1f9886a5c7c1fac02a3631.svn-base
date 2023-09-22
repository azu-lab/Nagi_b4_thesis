/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cSemaphore signature: sSemaphore context:task
 *   ER             cSemaphore_signal( );
 *   ER             cSemaphore_wait( );
 *   ER             cSemaphore_waitPolling( );
 *   ER             cSemaphore_waitTimeout( TMO timeout );
 *   ER             cSemaphore_initialize( );
 *   ER             cSemaphore_refer( T_RSEM* pk_semaphore_status );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tPutStringStdio_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# ePutString
 * entry port: ePutString
 * signature:  sPutString
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# ePutString_putString
 * name:         ePutString_putString
 * global_name:  tPutStringStdio_ePutString_putString
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
ePutString_putString(CELLIDX idx, const char_t* string)
{
	CELLCB	*p_cellcb;
  int i;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
  cSemaphore_wait( );
  i = 0;
  while( *string != 0 ){
      VAR_buf[i] = *string;
      string++;
      i++;
      if( i == ATTR_bufSize ){
          write( 1, VAR_buf, ATTR_bufSize );
          i = 0;
      }
  }
  if( i > 0 )
      write( 1, VAR_buf, i );
  cSemaphore_signal( );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
