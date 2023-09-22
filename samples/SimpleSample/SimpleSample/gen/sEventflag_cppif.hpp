#ifndef SEVENTFLAG_CPPIF_HPP
#define SEVENTFLAG_CPPIF_HPP
/*
 * C++ interface code
 *   This class comes from signature 'sEventflag'.
 *   All functions are pure virtual. These are defined in celltype class.
 */
 
 /* */
 class sEventflag {
    public:
    virtual ER set( FLGPTN set_pattern ) = 0;
    virtual ER clear( FLGPTN clear_pattern ) = 0;
    virtual ER wait( FLGPTN wait_pattern, MODE wait_flag_mode, FLGPTN* p_flag_pattern ) = 0;
    virtual ER waitPolling( FLGPTN wait_pattern, MODE wait_flag_mode, FLGPTN* p_flag_pattern ) = 0;
    virtual ER waitTimeout( FLGPTN wait_pattern, MODE wait_flag_mode, FLGPTN* p_flag_pattern, TMO timeout ) = 0;
    virtual ER initialize(  ) = 0;
    virtual ER refer( T_RFLG* pk_eventflag_status ) = 0;
};

#endif /* SEVENTFLAG_CPPIF_HPP */
