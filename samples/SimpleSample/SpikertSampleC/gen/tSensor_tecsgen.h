/*
 * This file was automatically generated by tecsgen.
 * This file is not intended to be edited.
 */
#ifndef tSensor_TECSGEN_H
#define tSensor_TECSGEN_H

/*
 * celltype          :  tSensor
 * global name       :  tSensor
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
#include "sPowerdown2_tecsgen.h"
#include "sSensor_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* cell INIB type definition #_CIP_# */
typedef const struct tag_tSensor_INIB {
    /* call port #_TCP_# */
    /* call port #_NEP_# */ 
    /* attribute(RO) #_ATO_# */ 
    pbio_port_id_t port;
}  tSensor_INIB;
/* cell CB type definition #_CCTPA_# */
typedef struct tag_tSensor_CB {
    tSensor_INIB  *_inib;
    /* call port #_TCP_# */
    /* call port #_NEP_# */ 
    /* var #_VA_# */ 
    pup_device_t*  ult;
}  tSensor_CB;
/* singleton cell CB prototype declaration #_MCPB_# */
extern tSensor_CB  tSensor_CB_tab[];

/* celltype IDX type #_CTIX_# */
typedef struct tag_tSensor_CB *tSensor_IDX;

/* prototype declaration of entry port function #_EPP_# */
/* sSensor */
void         tSensor_eSensor_set_device_ref(tSensor_IDX idx);
void         tSensor_eSensor_get_distance(tSensor_IDX idx, int32_t* distance);
pbio_error_t tSensor_eSensor_light_on(tSensor_IDX idx);
pbio_error_t tSensor_eSensor_light_set(tSensor_IDX idx, int32_t bv1, int32_t bv2, int32_t bv3, int32_t bv4);
pbio_error_t tSensor_eSensor_light_off(tSensor_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* to get the definition of CB type of referenced celltype for optimization #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tSensor_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tPowerdown_tecsgen.h"
#ifdef  tSensor_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tSensor_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define tSensor_ID_BASE             (1)  /* ID Base  #_NIDB_# */
#define tSensor_N_CELL              (1)  /*  number of cells  #_NCEL_# */

/* IDX validation macro #_CVI_# */
#define tSensor_VALID_IDX(IDX) (1)


/* celll CB macro #_GCB_# */
#define tSensor_GET_CELLCB(idx) (idx)

/* attr access  #_AAM_# */
#define tSensor_ATTR_port( p_that )	((p_that)->_inib->port)

#define tSensor_GET_port(p_that)	((p_that)->_inib->port)


/* var access macro #_VAM_# */
#define tSensor_VAR_ult(p_that)	((p_that)->ult)

#define tSensor_GET_ult(p_that)	((p_that)->ult)
#define tSensor_SET_ult(p_that,val)	((p_that)->ult=(val))

#ifndef TECSFLOW
 /* call port function macro #_CPM_# */
#define tSensor_cPowerdown_powerdown( p_that, ult ) \
	  tPowerdown_ePowerdown2_powerdown( \
	   (tPowerdown_IDX)0, (ult) )

#else  /* TECSFLOW */
#define tSensor_cPowerdown_powerdown( p_that, ult ) \
	  (p_that)->cPowerdown.powerdown__T( \
 (ult) )

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
#define VALID_IDX(IDX)  tSensor_VALID_IDX(IDX)


/* cell CB macro (abbrev) #_GCBA_# */
#define GET_CELLCB(idx)  tSensor_GET_CELLCB(idx)

/* CELLCB type (abbrev) #_CCT_# */
#define CELLCB	tSensor_CB

/* celltype IDX type (abbrev) #_CTIXA_# */
#define CELLIDX	tSensor_IDX


/* attr access macro (abbrev) #_AAMA_# */
#define ATTR_port            tSensor_ATTR_port( p_cellcb )


/* var access macro (abbrev) #_VAMA_# */
#define VAR_ult              tSensor_VAR_ult( p_cellcb )

/* call port function macro (abbrev) #_CPMA_# */
#define cPowerdown_powerdown( ult ) \
          ((void)p_cellcb, tSensor_cPowerdown_powerdown( p_cellcb, ult ))




/* entry port function macro (abbrev) #_EPM_# */
#define eSensor_set_device_ref tSensor_eSensor_set_device_ref
#define eSensor_get_distance tSensor_eSensor_get_distance
#define eSensor_light_on tSensor_eSensor_light_on
#define eSensor_light_set tSensor_eSensor_light_set
#define eSensor_light_off tSensor_eSensor_light_off

/* iteration code (FOREACH_CELL) #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tSensor_N_CELL; (i)++ ){ \
       (p_cb) = &tSensor_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB initialize macro #_CIM_# */
#define INITIALIZE_CB(p_that)\
	(p_that)->ult = NULL;
#define SET_CB_INIB_POINTER(i,p_that)\
	(p_that)->_inib = &tSensor_INIB_tab[(i)];

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tSensor_TECSGENH */
