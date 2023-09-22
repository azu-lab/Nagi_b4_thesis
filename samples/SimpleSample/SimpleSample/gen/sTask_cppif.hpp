#ifndef STASK_CPPIF_HPP
#define STASK_CPPIF_HPP
/*
 * C++ interface code
 *   This class comes from signature 'sTask'.
 *   All functions are pure virtual. These are defined in celltype class.
 */
 
 /* */
 class sTask {
    public:
    virtual ER activate(  ) = 0;
    virtual ER suspend(  ) = 0;
    virtual ER resume(  ) = 0;
};

#endif /* STASK_CPPIF_HPP */
