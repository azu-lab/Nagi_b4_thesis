/*
 * This file was automatically generated by tecsgen.
 * This file is not intended to be edited.
 */
#ifndef GLOBAL_TECSGEN_H
#define GLOBAL_TECSGEN_H


/* header imported by import_C #_IMP_# */
#include "tecs_kernel.h"
/**/

#ifndef TOPPERS_MACRO_ONLY

typedef int_t          TaskRef;
typedef int_t          pup_motor_t;
typedef int_t          pup_ultrasonic_sensor_t;
typedef int_t          pbio_error_t;
typedef int_t          pup_direction_t;
typedef int_t          pbio_port_id_t;
typedef int_t          Option_Ref_a_mut__pup_motor_t__;
typedef int_t          Option_Ref_a_mut__pup_ultrasonic_sensor_t__;
typedef int_t          bool;

#define INITIALIZE_TECS() 
#define INITIALZE_TECSGEN() INITIALIZE_TECS()  /* for backward compatibility */

/* Descriptor for dynamic join */
#define Descriptor( signature_global_name )  DynDesc__ ## signature_global_name
#define is_descriptor_unjoined( desc )  ((desc).vdes==NULL)

#endif /* TOPPERS_MACRO_ONLY */


#endif /* GLOBAL_TECSGEN_H */
