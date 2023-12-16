pub trait SPowerdown1 {
	#[inline]
	fn powerdown<'a>(&self, motor: &Option<&'a mut pup_motor_t>);
}
