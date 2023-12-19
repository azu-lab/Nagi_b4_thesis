/*
 * This file was automatically generated by tecsgen.
 * This file is not intended to be edited.
 */
#ifndef tMotor_TECSGEN_H
#define tMotor_TECSGEN_H

/*
 * celltype          :  tMotor
 * global name       :  tMotor
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
#include "sPowerdown1_tecsgen.h"
#include "sMotor_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* cell INIB type definition #_CIP_# */
typedef const struct tag_tMotor_INIB {
    /* call port #_TCP_# */
    struct tag_sPowerdown1_VDES const*cPowerdown; /* TCP_2 */
    /* call port #_NEP_# */ 
    /* attribute(RO) #_ATO_# */ 
    pbio_port_id_t port;
}  tMotor_INIB;
/* cell CB type definition #_CCTPA_# */
typedef struct tag_tMotor_CB {
    tMotor_INIB  *_inib;
    /* call port #_TCP_# */
    /* call port #_NEP_# */ 
    /* var #_VA_# */ 
    pup_motor_t*   motor;
}  tMotor_CB;
/* singleton cell CB prototype declaration #_MCPB_# */
extern tMotor_CB  tMotor_CB_tab[];

/* celltype IDX type #_CTIX_# */
typedef struct tag_tMotor_CB *tMotor_IDX;

/* prototype declaration of entry port function #_EPP_# */
/* sMotor */
void         tMotor_eMotor_set_motor_ref(tMotor_IDX idx);
pbio_error_t tMotor_eMotor_setup(tMotor_IDX idx, pup_direction_t positive_direction, bool reset_count);
pbio_error_t tMotor_eMotor_set_speed(tMotor_IDX idx, int32_t speed);
pbio_error_t tMotor_eMotor_stop(tMotor_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

#define tMotor_ID_BASE              (1)  /* ID Base  #_NIDB_# */
#define tMotor_N_CELL               (1)  /*  number of cells  #_NCEL_# */

/* IDX validation macro #_CVI_# */
#define tMotor_VALID_IDX(IDX) (1)


/* celll CB macro #_GCB_# */
#define tMotor_GET_CELLCB(idx) (idx)

/* attr access  #_AAM_# */
#define tMotor_ATTR_port( p_that )	((p_that)->_inib->port)

#define tMotor_GET_port(p_that)	((p_that)->_inib->port)


/* var access macro #_VAM_# */
#define tMotor_VAR_motor(p_that)	((p_that)->motor)

#define tMotor_GET_motor(p_that)	((p_that)->motor)
#define tMotor_SET_motor(p_that,val)	((p_that)->motor=(val))

#ifndef TECSFLOW
 /* call port function macro #_CPM_# */
#define tMotor_cPowerdown_powerdown( p_that, motor ) \
	  (p_that)->_inib->cPowerdown->VMT->powerdown__T( \
	   (p_that)->_inib->cPowerdown, (motor) )

#else  /* TECSFLOW */
#define tMotor_cPowerdown_powerdown( p_that, motor ) \
	  (p_that)->cPowerdown.powerdown__T( \
 (motor) )

#endif /* TECSFLOW */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* prototype declaration of entry port function (referenced when VMT useless optimise enabled) #_EPSP_# */
/* eMotor */
void           tMotor_eMotor_set_motor_ref_skel( const struct tag_sMotor_VDES *epd);
pbio_error_t   tMotor_eMotor_setup_skel( const struct tag_sMotor_VDES *epd, pup_direction_t positive_direction, bool reset_count);
pbio_error_t   tMotor_eMotor_set_speed_skel( const struct tag_sMotor_VDES *epd, int32_t speed);
pbio_error_t   tMotor_eMotor_stop_skel( const struct tag_sMotor_VDES *epd);

#ifndef TOPPERS_CB_TYPE_ONLY

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

/* IDX validation macro (abbrev.) #_CVIA_# */
#define VALID_IDX(IDX)  tMotor_VALID_IDX(IDX)


/* cell CB macro (abbrev) #_GCBA_# */
#define GET_CELLCB(idx)  tMotor_GET_CELLCB(idx)

/* CELLCB type (abbrev) #_CCT_# */
#define CELLCB	tMotor_CB

/* celltype IDX type (abbrev) #_CTIXA_# */
#define CELLIDX	tMotor_IDX


/* attr access macro (abbrev) #_AAMA_# */
#define ATTR_port            tMotor_ATTR_port( p_cellcb )


/* var access macro (abbrev) #_VAMA_# */
#define VAR_motor            tMotor_VAR_motor( p_cellcb )

/* call port function macro (abbrev) #_CPMA_# */
#define cPowerdown_powerdown( motor ) \
          tMotor_cPowerdown_powerdown( p_cellcb, motor )




/* entry port function macro (abbrev) #_EPM_# */
#define eMotor_set_motor_ref tMotor_eMotor_set_motor_ref
#define eMotor_setup     tMotor_eMotor_setup
#define eMotor_set_speed tMotor_eMotor_set_speed
#define eMotor_stop      tMotor_eMotor_stop

/* iteration code (FOREACH_CELL) #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tMotor_N_CELL; (i)++ ){ \
       (p_cb) = &tMotor_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB initialize macro #_CIM_# */
#define INITIALIZE_CB(p_that)\
	(p_that)->motor = NULL;
#define SET_CB_INIB_POINTER(i,p_that)\
	(p_that)->_inib = &tMotor_INIB_tab[(i)];

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tMotor_TECSGENH */
