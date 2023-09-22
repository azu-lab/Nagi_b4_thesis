#ifndef SIDATAQUEUE_CPPIF_HPP
#define SIDATAQUEUE_CPPIF_HPP
/*
 * C++ interface code
 *   This class comes from signature 'siDataqueue'.
 *   All functions are pure virtual. These are defined in celltype class.
 */
 
 /* */
 class siDataqueue {
    public:
    virtual ER sendPolling( intptr_t data ) = 0;
    virtual ER sendForce( intptr_t data ) = 0;
};

#endif /* SIDATAQUEUE_CPPIF_HPP */
