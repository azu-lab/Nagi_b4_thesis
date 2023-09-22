#ifndef SSEMAPHORE_CPPIF_HPP
#define SSEMAPHORE_CPPIF_HPP
/*
 * C++ interface code
 *   This class comes from signature 'sSemaphore'.
 *   All functions are pure virtual. These are defined in celltype class.
 */
 
 /* */
 class sSemaphore {
    public:
    virtual ER signal(  ) = 0;
    virtual ER wait(  ) = 0;
    virtual ER waitPolling(  ) = 0;
    virtual ER waitTimeout( TMO timeout ) = 0;
    virtual ER initialize(  ) = 0;
    virtual ER refer( T_RSEM* pk_semaphore_status ) = 0;
};

#endif /* SSEMAPHORE_CPPIF_HPP */
