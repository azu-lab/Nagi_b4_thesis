/*
 * This file was automatically generated by tecsgen.
 * Move and rename like below before editing,
 *   gen/tCarol_templ.c => src/tCarol.c
 * to avoid to be overwritten by tecsgen.
 */
/* #[<PREAMBLE>]#
 * Don't edit the comments between #[<...>]# and #[</...>]#
 * These comment are used by tecsmerege when merging.
 *
 * call port function #_TCPF_#
 * call port: cPerson signature: sHello context:task
 *   void           cPerson_Hello( );
 *
 * #[</PREAMBLE>]# */

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "tCarol_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eCarol
 * entry port: eCarol
 * signature:  sHello
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eCarol_Hello
 * name:         eCarol_Hello
 * global_name:  tCarol_eCarol_Hello
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCarol_Hello(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);

	/* Put statements here #_TEFB_# */
#warning "'eCarol_Hello' needs to be edited."   /* delete this line after edit */

}

/* #[<POSTAMBLE>]#
 *   Put non-entry functions below.
 * #[</POSTAMBLE>]#*/
