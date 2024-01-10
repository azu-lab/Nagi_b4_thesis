use spin::Mutex;
pub trait SMotor {
	#[inline]
	fn set_motor_ref(&self);
	#[inline]
	fn setup(&self, positive_direction: &pup_direction_t, reset_count: &bool);
	#[inline]
	fn set_speed(&self, speed: &i32);
	#[inline]
	fn stop(&self);
}
