/*
 * This file was automatically generated by tecsgen.
 * This file is not intended to be edited.
 */
#ifndef tCarol_TECSGEN_H
#define tCarol_TECSGEN_H

/*
 * celltype          :  tCarol
 * global name       :  tCarol
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
#include "sHello_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* cell CB (dummy) type definition #_CCDP_# */
typedef struct tag_tCarol_CB {
    int  dummy;
} tCarol_CB;
/* singleton cell CB prototype declaration #_MCPB_# */

/* celltype IDX type #_CTIX_# */
typedef int   tCarol_IDX;

/* prototype declaration of entry port function #_EPP_# */
/* sHello */
void         tCarol_eCarol_Hello(tCarol_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* to get the definition of CB type of referenced celltype for optimization #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tCarol_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tAlice_tecsgen.h"
#ifdef  tCarol_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tCarol_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define tCarol_ID_BASE              (1)  /* ID Base  #_NIDB_# */
#define tCarol_N_CELL               (1)  /*  number of cells  #_NCEL_# */

/* IDX validation macro #_CVI_# */
#define tCarol_VALID_IDX(IDX) (1)


/* celll CB macro #_GCB_# */
#define tCarol_GET_CELLCB(idx) ((void *)0)
#ifndef TECSFLOW
 /* call port function macro #_CPM_# */
#define tCarol_cPerson_Hello( p_that ) \
	  tAlice_eAlice_Hello( \
	   &tAlice_INIB_tab[1] )

#else  /* TECSFLOW */
#define tCarol_cPerson_Hello( p_that ) \
	  (p_that)->cPerson.Hello__T( \
 )

#endif /* TECSFLOW */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* prototype declaration of entry port function (referenced when VMT useless optimise enabled) #_EPSP_# */
/* eCarol */
void           tCarol_eCarol_Hello_skel( const struct tag_sHello_VDES *epd);

#ifndef TOPPERS_CB_TYPE_ONLY

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

/* IDX validation macro (abbrev.) #_CVIA_# */
#define VALID_IDX(IDX)  tCarol_VALID_IDX(IDX)


/* cell CB macro (abbrev) #_GCBA_# */
#define GET_CELLCB(idx)  tCarol_GET_CELLCB(idx)

/* CELLCB type (abbrev) #_CCT_# */
#define CELLCB	tCarol_CB

/* celltype IDX type (abbrev) #_CTIXA_# */
#define CELLIDX	tCarol_IDX

/* call port function macro (abbrev) #_CPMA_# */
#define cPerson_Hello( ) \
          ((void)p_cellcb, tCarol_cPerson_Hello( p_cellcb ))




/* entry port function macro (abbrev) #_EPM_# */
#define eCarol_Hello     tCarol_eCarol_Hello

/* iteration code (FOREACH_CELL) (niether CB, nor NIB exit) #_NFEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for((i)=0;(i)<0;(i)++){

#define END_FOREACH_CELL   }

/* CB initialize macro #_CIM_# */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tCarol_TECSGENH */
