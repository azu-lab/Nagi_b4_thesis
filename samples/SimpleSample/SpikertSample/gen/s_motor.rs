pub trait SMotor {

	fn set_motor_ref(&self);

	fn setup(&self, positive_direction: &pup_direction_t, reset_count: &bool)-> pbio_error_t;

	fn set_speed(&self, speed: &i32)-> pbio_error_t;

	fn stop(&self)-> pbio_error_t;

}
