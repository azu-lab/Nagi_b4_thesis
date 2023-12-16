pub trait SMotor {
	#[inline]
	fn set_motor_ref(&self);
	#[inline]
	fn setup(&self, positive_direction: &pup_direction_t, reset_count: &bool)-> pbio_error_t;
	#[inline]
	fn set_speed(&self, speed: &i32)-> pbio_error_t;
	#[inline]
	fn stop(&self)-> pbio_error_t;
}
