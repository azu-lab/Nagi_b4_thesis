#ifndef TSAMPLE_CPPIF_HPP
#define TSAMPLE_CPPIF_HPP

/*
 * This file is intended to be included in non-TECS celltype code and in C++ code.
 */
#include "tSample_tecsgen.h"
#include "sSample_cppif.hpp"

/*
 * Cell IDX type for Cpp
 */
typedef struct  {
    tSample_IDX idx;
} CPP_tSample_IDX;

/*
 * Cell IDX macros in celltype 'tSample'
 *   type of the macro value is tSample_IDX.
 *   macro name is (cell name) + "_IDX"
 */
inline CPP_tSample_IDX CPP_Sample_IDX__()
{
    CPP_tSample_IDX cpp_idx = { ((tSample_IDX)0) };
    return cpp_idx;
}
#define Sample_IDX  CPP_Sample_IDX__()

/*-------------- begin: use sample ------------
 * Define variable for Cell with Cnstructor
 *   tCelltypeName    CellNameInCpp( Cell_IDX );
 *   ex) tSample     Sample(Sample_IDX);
 *
 * Call member function
 *   CellNameInCpp.eEntryName.FunctionName( parameters... );
 *   ex) Sample.eEnt.sayHello( parameters... );
 *-------------- end:   use sample ------------*/

/*
 * C++ interface code
 *   This class comes from celltype 'tSample'.
 */
class tSample {
    /* class for entry sSample eEnt */
    class eEnt_ : public sSample{
        public : 
        /* constructor: internal use only */
        eEnt_(CPP_tSample_IDX idx_);
        /* destructor */
        // ~eEnt_();   unnecessary
    
        /* sSample functions */
        ER sayHello( int32_t times );
        ER howAreYou( char_t* buf, int32_t len );

        private:
        CPP_tSample_IDX cpp_idx;
    };

    /*--------  begin public ----------*/
    public:
    /* constructor */
    tSample( CPP_tSample_IDX idx_ );
    /* destructor */
    // ~tSample();   unnecessary

    /* entry sSample eEnt */
    eEnt_ eEnt; 
    /*--------  end public ----------*/
};

/*-------------- begin: implementation (I/F code only) ----------------*/
/* constructor  */
inline    tSample::tSample(CPP_tSample_IDX idx_) : eEnt(idx_){}

/* ------------- entry port: eEnt ------------------*/
/* constructor: internal use only */
inline    tSample::eEnt_::eEnt_( CPP_tSample_IDX idx_ ) :cpp_idx( idx_ ){}

/* entry eEnt functions */
inline ER tSample::eEnt_::sayHello( int32_t times ){ return tSample_eEnt_sayHello( cpp_idx.idx, times ); }
inline ER tSample::eEnt_::howAreYou( char_t* buf, int32_t len ){ return tSample_eEnt_howAreYou( cpp_idx.idx, buf, len ); }
/* undef for inline #_UDF_# */
#undef VALID_IDX
#undef GET_CELLCB
#undef CELLCB
#undef CELLIDX
#undef tSample_IDX
#undef FOREACH_CELL
#undef END_FOREACH_CELL
#undef INITIALIZE_CB
#undef SET_CB_INIB_POINTER
#undef eEnt_sayHello
#undef eEnt_howAreYou
/*-------------- end: implementation (I/F code only) ----------------*/

#endif /* TSAMPLE_CPPIF_HPP */
