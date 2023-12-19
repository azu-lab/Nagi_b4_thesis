/*
 * This file was automatically generated by tecsgen.
 * This file is not intended to be edited.
 */
#include "tSensor_tecsgen.h"
#include "tSensor_factory.h"

/* entry port descriptor type #_EDT_# */
/* eSensor */
struct tag_tSensor_eSensor_DES {
    const struct tag_sSensor_VMT *vmt;
    tSensor_IDX  idx;
};

/* entry port skelton function #_EPSF_# */
/* eSensor */
void           tSensor_eSensor_set_device_ref_skel( const struct tag_sSensor_VDES *epd)
{
    struct tag_tSensor_eSensor_DES *lepd
        = (struct tag_tSensor_eSensor_DES *)epd;
    tSensor_eSensor_set_device_ref( lepd->idx );
}
void           tSensor_eSensor_get_distance_skel( const struct tag_sSensor_VDES *epd, int32_t* distance)
{
    struct tag_tSensor_eSensor_DES *lepd
        = (struct tag_tSensor_eSensor_DES *)epd;
    tSensor_eSensor_get_distance( lepd->idx, distance );
}
pbio_error_t   tSensor_eSensor_light_on_skel( const struct tag_sSensor_VDES *epd)
{
    struct tag_tSensor_eSensor_DES *lepd
        = (struct tag_tSensor_eSensor_DES *)epd;
    return tSensor_eSensor_light_on( lepd->idx );
}
pbio_error_t   tSensor_eSensor_light_set_skel( const struct tag_sSensor_VDES *epd, int32_t bv1, int32_t bv2, int32_t bv3, int32_t bv4)
{
    struct tag_tSensor_eSensor_DES *lepd
        = (struct tag_tSensor_eSensor_DES *)epd;
    return tSensor_eSensor_light_set( lepd->idx, bv1, bv2, bv3, bv4 );
}
pbio_error_t   tSensor_eSensor_light_off_skel( const struct tag_sSensor_VDES *epd)
{
    struct tag_tSensor_eSensor_DES *lepd
        = (struct tag_tSensor_eSensor_DES *)epd;
    return tSensor_eSensor_light_off( lepd->idx );
}

/* entry port skelton function table #_EPSFT_# */
/* eSensor */
const struct tag_sSensor_VMT tSensor_eSensor_MT_ = {
    tSensor_eSensor_set_device_ref_skel,
    tSensor_eSensor_get_distance_skel,
    tSensor_eSensor_light_on_skel,
    tSensor_eSensor_light_set_skel,
    tSensor_eSensor_light_off_skel,
};

/* entry port descriptor referenced by call port (differ from actual definition) #_CPEPD_# */
extern struct tag_sPowerdown2_VDES Powerdown_ePowerdown2_des;

/* call port array #_CPA_# */

/* array of attr/var #_AVAI_# */
/* cell INIB #_INIB_# */
tSensor_INIB tSensor_INIB_tab[] = {
    /* cell: tSensor_CB_tab[0]:  Sensor id=1 */
    {
        /* call port (INIB) #_CP_# */ 
        &Powerdown_ePowerdown2_des,              /* cPowerdown #_CCP1_# */
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
        NULL,                                    /* ult */
    },
};

/* entry port descriptor #_EPD_# */
extern const struct tag_tSensor_eSensor_DES Sensor_eSensor_des;
const struct tag_tSensor_eSensor_DES Sensor_eSensor_des = {
    &tSensor_eSensor_MT_,
    &tSensor_CB_tab[0],      /* CB 3 */
};
