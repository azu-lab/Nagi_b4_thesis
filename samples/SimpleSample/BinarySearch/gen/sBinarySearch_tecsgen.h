/*
 * This file was automatically generated by tecsgen.
 * This file is not intended to be edited.
 */
#ifndef sBinarySearch_TECSGEN_H
#define sBinarySearch_TECSGEN_H

/*
 * signature   :  sBinarySearch
 * global name :  sBinarySearch
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* signature descriptor #_SD_# */
struct tag_sBinarySearch_VDES {
    struct tag_sBinarySearch_VMT *VMT;
};

/* signature function table #_SFT_# */
struct tag_sBinarySearch_VMT {
    int32_t        (*binary_search__T)( const struct tag_sBinarySearch_VDES *edp, int32_t key );
};

/* signature descriptor #_SDES_# for dynamic join */
#ifndef Descriptor_of_sBinarySearch_Defined
#define  Descriptor_of_sBinarySearch_Defined
typedef struct { struct tag_sBinarySearch_VDES *vdes; } Descriptor( sBinarySearch );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SBINARYSEARCH_BINARY_SEARCH     (1)

#endif /* sBinarySearch_TECSGEN_H */
