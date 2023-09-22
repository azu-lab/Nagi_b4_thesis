#include "tCell1_tecsgen.h"
#include <stdio.h>

/* 呼び口関数 */
/*
 * call port : cCall1  signature: sSig2
 *   int32_t cCall1_func1( THIS, int32_t a );
 *   int32_t cCall1_func2( THIS, int32_t a );
 */

/* 受け口関数 */
/*
 * entry port: eEntry1
 * signature:  sSig1
 */
/*
 * name:         eEntry1_func1
 * global_name:  tCell1_eEntry1_func1
 */
int32_t eEntry1_func1( tCell1_IDX idx, int32_t a)
{
  CELLCB      *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell1_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell1: eEntry1_func1( a=%d )\n", a );
  printf( "tCell1: eEntry1_func1: calling cCall_func1( this, a=101 )\n" );
  cCall1_func1( 101 );
}

/*
 * name:         eEntry1_func2
 * global_name:  tCell1_eEntry1_func2
 */
int32_t eEntry1_func2( tCell1_IDX idx, int32_t a)
{
  CELLCB      *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = tCell1_GET_CELLCB(idx);
  }else{
     /* エラー処理コードをここに記述 */
  }

  printf( "tCell1: eEntry1_func2( a=%d )\n", a );
  printf( "tCell1: eEntry1_func2: calling cCall_func2( this, a=201 )\n" );
  cCall1_func2( 201 );
}

