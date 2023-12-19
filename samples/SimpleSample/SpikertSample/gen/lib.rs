#![no_std]
#![feature(const_option)]
mod kernel_cfg;
mod task;
mod task_impl;
mod s_task;
mod si_task;
mod s_task_body;
mod si_notification_handler;
mod motor;
mod motor_impl;
mod s_powerdown;
mod s_motor;
mod sensor;
mod sensor_impl;
mod s_sensor;
mod taskbody;
mod taskbody_impl;
mod powerdown;
mod powerdown_impl;
