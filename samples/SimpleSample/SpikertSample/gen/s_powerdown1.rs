pub trait SPowerdown1 {

	fn powerdown<'a>(&self, motor: &Option<&'a mut pup_motor_t>);

}
