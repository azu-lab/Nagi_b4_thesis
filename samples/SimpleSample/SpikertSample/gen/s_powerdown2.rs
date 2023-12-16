pub trait SPowerdown2 {
	#[inline]
	fn powerdown<'a>(&self, ult: &Option<&'a mut pup_ultrasonic_sensor_t>);
}
