#ifndef SIKERNEL_CPPIF_HPP
#define SIKERNEL_CPPIF_HPP
/*
 * C++ interface code
 *   This class comes from signature 'siKernel'.
 *   All functions are pure virtual. These are defined in celltype class.
 */
 
 /* */
 class siKernel {
    public:
    virtual ER getMicroTime( SYSUTM* p_system_micro_time ) = 0;
};

#endif /* SIKERNEL_CPPIF_HPP */
