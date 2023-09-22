#ifndef SKERNEL_CPPIF_HPP
#define SKERNEL_CPPIF_HPP
/*
 * C++ interface code
 *   This class comes from signature 'sKernel'.
 *   All functions are pure virtual. These are defined in celltype class.
 */
 
 /* */
 class sKernel {
    public:
    virtual ER delay( RELTIM delay_time ) = 0;
    virtual ER exitTask(  ) = 0;
    virtual ER getTime( SYSTIM* p_system_time ) = 0;
    virtual ER getMicroTime( SYSUTM* p_system_micro_time ) = 0;
    virtual ER exitKernel(  ) = 0;
};

#endif /* SKERNEL_CPPIF_HPP */
