#ifndef SIEVENTFLAG_CPPIF_HPP
#define SIEVENTFLAG_CPPIF_HPP
/*
 * C++ interface code
 *   This class comes from signature 'siEventflag'.
 *   All functions are pure virtual. These are defined in celltype class.
 */
 
 /* */
 class siEventflag {
    public:
    virtual ER set( FLGPTN set_pattern ) = 0;
};

#endif /* SIEVENTFLAG_CPPIF_HPP */
