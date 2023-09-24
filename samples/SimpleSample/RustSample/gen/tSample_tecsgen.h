/*
 * This file was automatically generated by tecsgen.
 * This file is not intended to be edited.
 */
#ifndef tSample_TECSGEN_H
#define tSample_TECSGEN_H

/*
 * celltype          :  tSample
 * global name       :  tSample
 * multi-domain      :  no
 * idx_is_id(actual) :  no(no)
 * singleton         :  no
 * has_CB            :  no
 * has_INIB          :  no
 * rom               :  yes
 * CB initializer    :  no
 */

/* global header #_IGH_# */
#include "global_tecsgen.h"

/* signature header #_ISH_# */
#include "sSample_tecsgen.h"
#include "sSample2_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* cell CB (dummy) type definition #_CCDP_# */
typedef struct tag_tSample_CB {
    int  dummy;
} tSample_CB;
/* singleton cell CB prototype declaration #_MCPB_# */

/* celltype IDX type #_CTIX_# */
typedef int   tSample_IDX;
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* to get the definition of CB type of referenced celltype for optimization #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tSample_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tPrint_tecsgen.h"
#ifdef  tSample_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tSample_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define tSample_ID_BASE             (1)  /* ID Base  #_NIDB_# */
#define tSample_N_CELL              (1)  /*  number of cells  #_NCEL_# */

/* IDX validation macro #_CVI_# */
#define tSample_VALID_IDX(IDX) (1)


/* celll CB macro #_GCB_# */
#define tSample_GET_CELLCB(idx) ((void *)0)
#ifndef TECSFLOW
 /* call port function macro #_CPM_# */
#define tSample_cPrint_print( p_that, varin, varout, varout2 ) \
	  tPrint_ePrint_print( \
	   &tPrint_CB_tab[0], (varin), (varout), (varout2) )
#define tSample_cPrint2_print( p_that ) \
	  tPrint_ePrint2_print( \
	   &tPrint_CB_tab[0] )

#else  /* TECSFLOW */
#define tSample_cPrint_print( p_that, varin, varout, varout2 ) \
	  (p_that)->cPrint.print__T( \
 (varin), (varout), (varout2) )
#define tSample_cPrint2_print( p_that ) \
	  (p_that)->cPrint2.print__T( \
 )

#endif /* TECSFLOW */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef TOPPERS_CB_TYPE_ONLY

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

/* IDX validation macro (abbrev.) #_CVIA_# */
#define VALID_IDX(IDX)  tSample_VALID_IDX(IDX)


/* cell CB macro (abbrev) #_GCBA_# */
#define GET_CELLCB(idx)  tSample_GET_CELLCB(idx)

/* CELLCB type (abbrev) #_CCT_# */
#define CELLCB	tSample_CB

/* celltype IDX type (abbrev) #_CTIXA_# */
#define CELLIDX	tSample_IDX

/* call port function macro (abbrev) #_CPMA_# */
#define cPrint_print( varin, varout, varout2 ) \
          ((void)p_cellcb, tSample_cPrint_print( p_cellcb, varin, varout, varout2 ))
#define cPrint2_print( ) \
          ((void)p_cellcb, tSample_cPrint2_print( p_cellcb ))



/* iteration code (FOREACH_CELL) (niether CB, nor NIB exit) #_NFEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for((i)=0;(i)<0;(i)++){

#define END_FOREACH_CELL   }

/* CB initialize macro #_CIM_# */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tSample_TECSGENH */
