#ifndef SDATAQUEUE_CPPIF_HPP
#define SDATAQUEUE_CPPIF_HPP
/*
 * C++ interface code
 *   This class comes from signature 'sDataqueue'.
 *   All functions are pure virtual. These are defined in celltype class.
 */
 
 /* */
 class sDataqueue {
    public:
    virtual ER send( intptr_t data ) = 0;
    virtual ER sendPolling( intptr_t data ) = 0;
    virtual ER sendTimeout( intptr_t data, TMO timeout ) = 0;
    virtual ER sendForce( intptr_t data ) = 0;
    virtual ER receive( intptr_t* p_data ) = 0;
    virtual ER receivePolling( intptr_t* p_data ) = 0;
    virtual ER receiveTimeout( intptr_t* p_data, TMO timeout ) = 0;
    virtual ER initialize(  ) = 0;
    virtual ER refer( T_RDTQ* pk_dataqueue_status ) = 0;
};

#endif /* SDATAQUEUE_CPPIF_HPP */
