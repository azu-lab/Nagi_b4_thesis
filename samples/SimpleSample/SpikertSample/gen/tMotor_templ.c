/*
 * This file was automatically generated by tecsgen.
 * Move and rename like below before editing,
 *   gen/tMotor_templ.c => src/tMotor.c
 * to avoid to be overwritten by tecsgen.
 */
/* #[<PREAMBLE>]#
 * Don't edit the comments between #[<...>]# and #[</...>]#
 * These comment are used by tecsmerege when merging.
 *
 * attr access macro #_CAAM_#
 * port             pbio_port_id_t   ATTR_port       
 * motor            Option_Ref_a_mut__pup_motor_t__  VAR_motor       
 *
 * call port function #_TCPF_#
 * call port: cPowerdown signature: sPowerdown context:task
 *   void           cPowerdown_powerdown( pbio_error_t error );
 *
 * #[</PREAMBLE>]# */

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "tMotor_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eMotor
 * entry port: eMotor
 * signature:  sMotor
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMotor_set_motor_ref
 * name:         eMotor_set_motor_ref
 * global_name:  tMotor_eMotor_set_motor_ref
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMotor_set_motor_ref(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);

	/* Put statements here #_TEFB_# */
#warning "'eMotor_set_motor_ref' needs to be edited."   /* delete this line after edit */

}

/* #[<ENTRY_FUNC>]# eMotor_setup
 * name:         eMotor_setup
 * global_name:  tMotor_eMotor_setup
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMotor_setup(CELLIDX idx, pup_direction_t positive_direction, bool reset_count)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);

	/* Put statements here #_TEFB_# */
#warning "'eMotor_setup' needs to be edited."   /* delete this line after edit */

}

/* #[<ENTRY_FUNC>]# eMotor_set_speed
 * name:         eMotor_set_speed
 * global_name:  tMotor_eMotor_set_speed
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMotor_set_speed(CELLIDX idx, int32_t speed)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);

	/* Put statements here #_TEFB_# */
#warning "'eMotor_set_speed' needs to be edited."   /* delete this line after edit */

}

/* #[<ENTRY_FUNC>]# eMotor_stop
 * name:         eMotor_stop
 * global_name:  tMotor_eMotor_stop
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMotor_stop(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);

	/* Put statements here #_TEFB_# */
#warning "'eMotor_stop' needs to be edited."   /* delete this line after edit */

}

/* #[<POSTAMBLE>]#
 *   Put non-entry functions below.
 * #[</POSTAMBLE>]#*/
