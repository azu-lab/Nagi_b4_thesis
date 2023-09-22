#ifndef TSIMPLE_CPPIF_HPP
#define TSIMPLE_CPPIF_HPP

/*
 * This file is intended to be included in non-TECS celltype code and in C++ code.
 */
#include "tSimple_tecsgen.h"
#include "sTaskBody_cppif.hpp"


/*-------------- begin: use sample ------------
 * Define variable for Cell with Cnstructor
 *   tCelltypeName    CellNameInCpp;     // don't put empty parenthesis for singleton
 *   ex) tSimple     Simple;
 *
 * Call member function
 *   CellNameInCpp.eEntryName.FunctionName( parameters... );
 *   ex) Simple.eBody.main( parameters... );
 *-------------- end:   use sample ------------*/

/*
 * C++ interface code
 *   This class comes from celltype 'tSimple'.
 */
class tSimple {
    /* class for entry sTaskBody eBody */
    class eBody_ : public sTaskBody{
        public : 
        /* constructor: internal use only */
        eBody_();
        /* destructor */
        // ~eBody_();   unnecessary
    
        /* sTaskBody functions */
        void main(  );

    };

    /*--------  begin public ----------*/
    public:
    /* constructor */
    tSimple(  );
    /* destructor */
    // ~tSimple();   unnecessary

    /* entry sSample cCall */
    cCall_ cCall; 
    /* entry sTaskBody eBody */
    eBody_ eBody; 
    /*--------  end public ----------*/
};

/*-------------- begin: implementation (I/F code only) ----------------*/
/* constructor  */
inline    tSimple::tSimple() : eBody(){}

/* ------------- entry port: cCall ------------------*/
/* constructor: internal use only */
inline    tSimple::cCall_::cCall_(  ) {}

/* entry cCall functions */
inline ER tSimple::cCall_::sayHello( int32_t times ){ return tSimple_cCall_sayHello( times ); }
inline ER tSimple::cCall_::howAreYou( char_t* buf, int32_t len ){ return tSimple_cCall_howAreYou( buf, len ); }
/* ------------- entry port: eBody ------------------*/
/* constructor: internal use only */
inline    tSimple::eBody_::eBody_(  ) {}

/* entry eBody functions */
inline void tSimple::eBody_::main(  ){ tSimple_eBody_main(  ); }
/* undef for inline #_UDF_# */
#undef VALID_IDX
#undef GET_CELLCB
#undef CELLCB
#undef CELLIDX
#undef tSimple_IDX
#undef FOREACH_CELL
#undef END_FOREACH_CELL
#undef INITIALIZE_CB
#undef SET_CB_INIB_POINTER
#undef tSimple_cCall_sayHello
#undef cCall_sayHello
#undef tSimple_cCall_howAreYou
#undef cCall_howAreYou
#undef eBody_main
/*-------------- end: implementation (I/F code only) ----------------*/

#endif /* TSIMPLE_CPPIF_HPP */
