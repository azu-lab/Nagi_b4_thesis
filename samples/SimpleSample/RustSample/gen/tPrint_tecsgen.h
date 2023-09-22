/*
 * This file was automatically generated by tecsgen.
 * This file is not intended to be edited.
 */
#ifndef tPrint_TECSGEN_H
#define tPrint_TECSGEN_H

/*
 * celltype          :  tPrint
 * global name       :  tPrint
 * multi-domain      :  no
 * idx_is_id(actual) :  no(no)
 * singleton         :  no
 * has_CB            :  yes
 * has_INIB          :  yes
 * rom               :  yes
 * CB initializer    :  yes
 */

/* global header #_IGH_# */
#include "global_tecsgen.h"

/* signature header #_ISH_# */
#include "sSample_tecsgen.h"
#include "sAllocator_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* cell INIB type definition #_CIP_# */
typedef const struct tag_tPrint_INIB {
    /* call port #_TCP_# */
    /* call port #_NEP_# */ 
    /* attribute(RO) #_ATO_# */ 
    int16_t        attribute;
}  tPrint_INIB;
/* cell CB type definition #_CCTPA_# */
typedef struct tag_tPrint_CB {
    tPrint_INIB  *_inib;
    /* call port #_TCP_# */
    /* call port #_NEP_# */ 
    /* var #_VA_# */ 
    int16_t        variable;
}  tPrint_CB;
/* singleton cell CB prototype declaration #_MCPB_# */
extern tPrint_CB  tPrint_CB_tab[];

/* celltype IDX type #_CTIX_# */
typedef struct tag_tPrint_CB *tPrint_IDX;

/* prototype declaration of entry port function #_EPP_# */
/* sSample */
void         tPrint_ePrint_print(tPrint_IDX idx, int8_t varin, int8_t* varsend, int16_t length, int32_t* varout, int32_t* varout2);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* to get the definition of CB type of referenced celltype for optimization #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tPrint_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tAllocator_tecsgen.h"
#ifdef  tPrint_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tPrint_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define tPrint_ID_BASE              (1)  /* ID Base  #_NIDB_# */
#define tPrint_N_CELL               (1)  /*  number of cells  #_NCEL_# */

/* IDX validation macro #_CVI_# */
#define tPrint_VALID_IDX(IDX) (1)


/* celll CB macro #_GCB_# */
#define tPrint_GET_CELLCB(idx) (idx)

/* attr access  #_AAM_# */
#define tPrint_ATTR_attribute( p_that )	((p_that)->_inib->attribute)

#define tPrint_GET_attribute(p_that)	((p_that)->_inib->attribute)


/* var access macro #_VAM_# */
#define tPrint_VAR_variable(p_that)	((p_that)->variable)

#define tPrint_GET_variable(p_that)	((p_that)->variable)
#define tPrint_SET_variable(p_that,val)	((p_that)->variable=(val))

#ifndef TECSFLOW
 /* call port function macro #_CPM_# */
#define tPrint_ePrint_print_varsend_alloc( p_that, size, buf ) \
	  tAllocator_eAlloc_alloc( \
	   (tAllocator_IDX)0, (size), (buf) )
#define tPrint_ePrint_print_varsend_dealloc( p_that, buf ) \
	  tAllocator_eAlloc_dealloc( \
	   (tAllocator_IDX)0, (buf) )

#else  /* TECSFLOW */
#define tPrint_ePrint_print_varsend_alloc( p_that, size, buf ) \
	  (p_that)->ePrint_print_varsend.alloc__T( \
 (size), (buf) )
#define tPrint_ePrint_print_varsend_dealloc( p_that, buf ) \
	  (p_that)->ePrint_print_varsend.dealloc__T( \
 (buf) )

#endif /* TECSFLOW */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* prototype declaration of entry port function (referenced when VMT useless optimise enabled) #_EPSP_# */

#ifndef TOPPERS_CB_TYPE_ONLY

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

/* IDX validation macro (abbrev.) #_CVIA_# */
#define VALID_IDX(IDX)  tPrint_VALID_IDX(IDX)


/* cell CB macro (abbrev) #_GCBA_# */
#define GET_CELLCB(idx)  tPrint_GET_CELLCB(idx)

/* CELLCB type (abbrev) #_CCT_# */
#define CELLCB	tPrint_CB

/* celltype IDX type (abbrev) #_CTIXA_# */
#define CELLIDX	tPrint_IDX


/* attr access macro (abbrev) #_AAMA_# */
#define ATTR_attribute       tPrint_ATTR_attribute( p_cellcb )


/* var access macro (abbrev) #_VAMA_# */
#define VAR_variable         tPrint_VAR_variable( p_cellcb )

/* call port function macro (abbrev) #_CPMA_# */
#define ePrint_print_varsend_alloc( size, buf ) \
          ((void)p_cellcb, tPrint_ePrint_print_varsend_alloc( p_cellcb, size, buf ))
#define ePrint_print_varsend_dealloc( buf ) \
          ((void)p_cellcb, tPrint_ePrint_print_varsend_dealloc( p_cellcb, buf ))




/* entry port function macro (abbrev) #_EPM_# */
#define ePrint_print     tPrint_ePrint_print

/* iteration code (FOREACH_CELL) #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tPrint_N_CELL; (i)++ ){ \
       (p_cb) = &tPrint_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB initialize macro #_CIM_# */
#define INITIALIZE_CB(p_that)\
	(p_that)->variable = 0;
#define SET_CB_INIB_POINTER(i,p_that)\
	(p_that)->_inib = &tPrint_INIB_tab[(i)];


/* deallocate macro #_DAL_#   */
#define EPRINT_PRINT_VARSEND_DEALLOC(varsend) \
	  ePrint_print_varsend_dealloc( (varsend) ); 

/* deallocate macro #_DAL_#  _RESET */
#define EPRINT_PRINT_VARSEND_DEALLOC_RESET(varsend) \
	  if( (varsend) ){ \
	    ePrint_print_varsend_dealloc( (varsend) );  \
	  }
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tPrint_TECSGENH */
