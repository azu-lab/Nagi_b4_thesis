/*
 * This file was automatically generated by tecsgen.
 * This file is not intended to be edited.
 */
#include "tTaskbody2_tecsgen.h"
#include "tTaskbody2_factory.h"

/* entry port descriptor type #_EDT_# */
/* eTaskbody */
struct tag_tTaskbody2_eTaskbody_DES {
    const struct tag_sTaskBody_VMT *vmt;
    int           idx;
};

/* entry port skelton function #_EPSF_# */
/* eTaskbody */
void           tTaskbody2_eTaskbody_main_skel( const struct tag_sTaskBody_VDES *epd)
{
    struct tag_tTaskbody2_eTaskbody_DES *lepd
        = (struct tag_tTaskbody2_eTaskbody_DES *)epd;
    tTaskbody2_eTaskbody_main( lepd->idx );
}

/* entry port skelton function table #_EPSFT_# */
/* eTaskbody */
const struct tag_sTaskBody_VMT tTaskbody2_eTaskbody_MT_ = {
    tTaskbody2_eTaskbody_main_skel,
};

/* entry port descriptor referenced by call port (differ from actual definition) #_CPEPD_# */

/* call port array #_CPA_# */

/* array of attr/var #_AVAI_# */
/* entry port descriptor #_EPD_# */
extern const struct tag_tTaskbody2_eTaskbody_DES Taskbody2_eTaskbody_des;
const struct tag_tTaskbody2_eTaskbody_DES Taskbody2_eTaskbody_des = {
    &tTaskbody2_eTaskbody_MT_,
    0,
};
