/*
 * This file was automatically generated by tecsgen.
 * This file is not intended to be edited.
 */
#ifndef tTaskbody_TECSGEN_H
#define tTaskbody_TECSGEN_H

/*
 * celltype          :  tTaskbody
 * global name       :  tTaskbody
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
#include "sTaskBody_tecsgen.h"
#include "sTask_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* cell CB (dummy) type definition #_CCDP_# */
typedef struct tag_tTaskbody_CB {
    int  dummy;
} tTaskbody_CB;
/* singleton cell CB prototype declaration #_MCPB_# */

/* celltype IDX type #_CTIX_# */
typedef int   tTaskbody_IDX;

/* prototype declaration of entry port function #_EPP_# */
/* sTaskBody */
void         tTaskbody_eTaskbody_main(tTaskbody_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* to get the definition of CB type of referenced celltype for optimization #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tTaskbody_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tTask_rs_tecsgen.h"
#ifdef  tTaskbody_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tTaskbody_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define tTaskbody_ID_BASE           (1)  /* ID Base  #_NIDB_# */
#define tTaskbody_N_CELL            (1)  /*  number of cells  #_NCEL_# */

/* IDX validation macro #_CVI_# */
#define tTaskbody_VALID_IDX(IDX) (1)


/* celll CB macro #_GCB_# */
#define tTaskbody_GET_CELLCB(idx) ((void *)0)
#ifndef TECSFLOW
 /* call port function macro #_CPM_# */
#define tTaskbody_cTask_activate( p_that ) \
	  tTask_rs_eTask_activate( \
	   &tTask_rs_INIB_tab[1] )
#define tTaskbody_cTask_cancelActivate( p_that ) \
	  tTask_rs_eTask_cancelActivate( \
	   &tTask_rs_INIB_tab[1] )
#define tTaskbody_cTask_getTaskState( p_that, p_tskstat ) \
	  tTask_rs_eTask_getTaskState( \
	   &tTask_rs_INIB_tab[1], (p_tskstat) )
#define tTaskbody_cTask_changePriority( p_that, priority ) \
	  tTask_rs_eTask_changePriority( \
	   &tTask_rs_INIB_tab[1], (priority) )
#define tTaskbody_cTask_getPriority( p_that, p_priority ) \
	  tTask_rs_eTask_getPriority( \
	   &tTask_rs_INIB_tab[1], (p_priority) )
#define tTaskbody_cTask_refer( p_that, pk_taskStatus ) \
	  tTask_rs_eTask_refer( \
	   &tTask_rs_INIB_tab[1], (pk_taskStatus) )
#define tTaskbody_cTask_wakeup( p_that ) \
	  tTask_rs_eTask_wakeup( \
	   &tTask_rs_INIB_tab[1] )
#define tTaskbody_cTask_cancelWakeup( p_that ) \
	  tTask_rs_eTask_cancelWakeup( \
	   &tTask_rs_INIB_tab[1] )
#define tTaskbody_cTask_releaseWait( p_that ) \
	  tTask_rs_eTask_releaseWait( \
	   &tTask_rs_INIB_tab[1] )
#define tTaskbody_cTask_suspend( p_that ) \
	  tTask_rs_eTask_suspend( \
	   &tTask_rs_INIB_tab[1] )
#define tTaskbody_cTask_resume( p_that ) \
	  tTask_rs_eTask_resume( \
	   &tTask_rs_INIB_tab[1] )
#define tTaskbody_cTask_raiseTerminate( p_that ) \
	  tTask_rs_eTask_raiseTerminate( \
	   &tTask_rs_INIB_tab[1] )
#define tTaskbody_cTask_terminate( p_that ) \
	  tTask_rs_eTask_terminate( \
	   &tTask_rs_INIB_tab[1] )

#else  /* TECSFLOW */
#define tTaskbody_cTask_activate( p_that ) \
	  (p_that)->cTask.activate__T( \
 )
#define tTaskbody_cTask_cancelActivate( p_that ) \
	  (p_that)->cTask.cancelActivate__T( \
 )
#define tTaskbody_cTask_getTaskState( p_that, p_tskstat ) \
	  (p_that)->cTask.getTaskState__T( \
 (p_tskstat) )
#define tTaskbody_cTask_changePriority( p_that, priority ) \
	  (p_that)->cTask.changePriority__T( \
 (priority) )
#define tTaskbody_cTask_getPriority( p_that, p_priority ) \
	  (p_that)->cTask.getPriority__T( \
 (p_priority) )
#define tTaskbody_cTask_refer( p_that, pk_taskStatus ) \
	  (p_that)->cTask.refer__T( \
 (pk_taskStatus) )
#define tTaskbody_cTask_wakeup( p_that ) \
	  (p_that)->cTask.wakeup__T( \
 )
#define tTaskbody_cTask_cancelWakeup( p_that ) \
	  (p_that)->cTask.cancelWakeup__T( \
 )
#define tTaskbody_cTask_releaseWait( p_that ) \
	  (p_that)->cTask.releaseWait__T( \
 )
#define tTaskbody_cTask_suspend( p_that ) \
	  (p_that)->cTask.suspend__T( \
 )
#define tTaskbody_cTask_resume( p_that ) \
	  (p_that)->cTask.resume__T( \
 )
#define tTaskbody_cTask_raiseTerminate( p_that ) \
	  (p_that)->cTask.raiseTerminate__T( \
 )
#define tTaskbody_cTask_terminate( p_that ) \
	  (p_that)->cTask.terminate__T( \
 )

#endif /* TECSFLOW */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* prototype declaration of entry port function (referenced when VMT useless optimise enabled) #_EPSP_# */
/* eTaskbody */
void           tTaskbody_eTaskbody_main_skel( const struct tag_sTaskBody_VDES *epd);

#ifndef TOPPERS_CB_TYPE_ONLY

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

/* IDX validation macro (abbrev.) #_CVIA_# */
#define VALID_IDX(IDX)  tTaskbody_VALID_IDX(IDX)


/* cell CB macro (abbrev) #_GCBA_# */
#define GET_CELLCB(idx)  tTaskbody_GET_CELLCB(idx)

/* CELLCB type (abbrev) #_CCT_# */
#define CELLCB	tTaskbody_CB

/* celltype IDX type (abbrev) #_CTIXA_# */
#define CELLIDX	tTaskbody_IDX

/* call port function macro (abbrev) #_CPMA_# */
#define cTask_activate( ) \
          ((void)p_cellcb, tTaskbody_cTask_activate( p_cellcb ))
#define cTask_cancelActivate( ) \
          ((void)p_cellcb, tTaskbody_cTask_cancelActivate( p_cellcb ))
#define cTask_getTaskState( p_tskstat ) \
          ((void)p_cellcb, tTaskbody_cTask_getTaskState( p_cellcb, p_tskstat ))
#define cTask_changePriority( priority ) \
          ((void)p_cellcb, tTaskbody_cTask_changePriority( p_cellcb, priority ))
#define cTask_getPriority( p_priority ) \
          ((void)p_cellcb, tTaskbody_cTask_getPriority( p_cellcb, p_priority ))
#define cTask_refer( pk_taskStatus ) \
          ((void)p_cellcb, tTaskbody_cTask_refer( p_cellcb, pk_taskStatus ))
#define cTask_wakeup( ) \
          ((void)p_cellcb, tTaskbody_cTask_wakeup( p_cellcb ))
#define cTask_cancelWakeup( ) \
          ((void)p_cellcb, tTaskbody_cTask_cancelWakeup( p_cellcb ))
#define cTask_releaseWait( ) \
          ((void)p_cellcb, tTaskbody_cTask_releaseWait( p_cellcb ))
#define cTask_suspend( ) \
          ((void)p_cellcb, tTaskbody_cTask_suspend( p_cellcb ))
#define cTask_resume( ) \
          ((void)p_cellcb, tTaskbody_cTask_resume( p_cellcb ))
#define cTask_raiseTerminate( ) \
          ((void)p_cellcb, tTaskbody_cTask_raiseTerminate( p_cellcb ))
#define cTask_terminate( ) \
          ((void)p_cellcb, tTaskbody_cTask_terminate( p_cellcb ))




/* entry port function macro (abbrev) #_EPM_# */
#define eTaskbody_main   tTaskbody_eTaskbody_main

/* iteration code (FOREACH_CELL) (niether CB, nor NIB exit) #_NFEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for((i)=0;(i)<0;(i)++){

#define END_FOREACH_CELL   }

/* CB initialize macro #_CIM_# */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tTaskbody_TECSGENH */
