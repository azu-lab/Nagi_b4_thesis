/*
 * This file was automatically generated by tecsgen.
 * This file is not intended to be edited.
 */
#include "tSensor_tecsgen.h"
#include "tSensor_factory.h"

/* entry port descriptor type #_EDT_# */
/* eSensor : omitted by entry port optimize */

/* entry port skelton function #_EPSF_# */
/* eSensor : omitted by entry port optimize */

/* entry port skelton function table #_EPSFT_# */
/* eSensor : omitted by entry port optimize */

/* entry port descriptor referenced by call port (differ from actual definition) #_CPEPD_# */

/* call port array #_CPA_# */

/* array of attr/var #_AVAI_# */
/* cell INIB #_INIB_# */
tSensor_INIB tSensor_INIB_tab[] = {
    /* cell: tSensor_CB_tab[0]:  Sensor id=1 */
    {
        /* entry port #_EP_# */ 
        /* attribute(RO) */ 
        PBIO_PORT_ID_B,                          /* port */
    },
};

/* cell CB #_CB_# */
struct tag_tSensor_CB tSensor_CB_tab[] = {
    /* cell: tSensor_CB_tab[0]:  Sensor id=1 */
    {
        &tSensor_INIB_tab[0],                    /* _inib */
        /* entry port #_EP_# */ 
        /* var */ 
        None,                                    /* ult */
    },
};

/* entry port descriptor #_EPD_# */
/* eSensor : omitted by entry port optimize */
