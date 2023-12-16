/*
 * This file was automatically generated by tecsgen.
 * This file is not intended to be edited.
 */
#ifndef tPowerdown_TECSGEN_H
#define tPowerdown_TECSGEN_H

/*
 * celltype          :  tPowerdown
 * global name       :  tPowerdown
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
#include "sPowerdown1_tecsgen.h"
#include "sPowerdown2_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* cell CB (dummy) type definition #_CCDP_# */
typedef struct tag_tPowerdown_CB {
    int  dummy;
} tPowerdown_CB;
/* singleton cell CB prototype declaration #_MCPB_# */

/* celltype IDX type #_CTIX_# */
typedef int   tPowerdown_IDX;

/* prototype declaration of entry port function #_EPP_# */
/* sPowerdown1 */
void         tPowerdown_ePowerdown1_powerdown(tPowerdown_IDX idx, const pup_motor_t* motor);
/* sPowerdown2 */
void         tPowerdown_ePowerdown2_powerdown(tPowerdown_IDX idx, const pup_device_t* ult);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

#define tPowerdown_ID_BASE          (1)  /* ID Base  #_NIDB_# */
#define tPowerdown_N_CELL           (1)  /*  number of cells  #_NCEL_# */

/* IDX validation macro #_CVI_# */
#define tPowerdown_VALID_IDX(IDX) (1)


/* celll CB macro #_GCB_# */
#define tPowerdown_GET_CELLCB(idx) ((void *)0)
#ifndef TECSFLOW
#else  /* TECSFLOW */
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
#define VALID_IDX(IDX)  tPowerdown_VALID_IDX(IDX)


/* cell CB macro (abbrev) #_GCBA_# */
#define GET_CELLCB(idx)  tPowerdown_GET_CELLCB(idx)

/* CELLCB type (abbrev) #_CCT_# */
#define CELLCB	tPowerdown_CB

/* celltype IDX type (abbrev) #_CTIXA_# */
#define CELLIDX	tPowerdown_IDX




/* entry port function macro (abbrev) #_EPM_# */
#define ePowerdown1_powerdown tPowerdown_ePowerdown1_powerdown
#define ePowerdown2_powerdown tPowerdown_ePowerdown2_powerdown

/* iteration code (FOREACH_CELL) (niether CB, nor NIB exit) #_NFEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for((i)=0;(i)<0;(i)++){

#define END_FOREACH_CELL   }

/* CB initialize macro #_CIM_# */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tPowerdown_TECSGENH */
