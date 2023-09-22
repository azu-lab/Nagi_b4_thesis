#ifndef SISEMAPHORE_CPPIF_HPP
#define SISEMAPHORE_CPPIF_HPP
/*
 * C++ interface code
 *   This class comes from signature 'siSemaphore'.
 *   All functions are pure virtual. These are defined in celltype class.
 */
 
 /* */
 class siSemaphore {
    public:
    virtual ER signal(  ) = 0;
};

#endif /* SISEMAPHORE_CPPIF_HPP */
