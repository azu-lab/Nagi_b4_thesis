#ifndef SSAMPLE_CPPIF_HPP
#define SSAMPLE_CPPIF_HPP
/*
 * C++ interface code
 *   This class comes from signature 'sSample'.
 *   All functions are pure virtual. These are defined in celltype class.
 */
 
 /* */
 class sSample {
    public:
    virtual ER sayHello( int32_t times ) = 0;
    virtual ER howAreYou( char_t* buf, int32_t len ) = 0;
};

#endif /* SSAMPLE_CPPIF_HPP */
