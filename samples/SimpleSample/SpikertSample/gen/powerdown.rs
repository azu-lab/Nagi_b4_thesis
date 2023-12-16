use crate::{s_powerdown1::*, s_powerdown2::*};

pub struct Powerdown
{
}

pub static POWERDOWN: Powerdown = Powerdown {
};

pub struct EPowerdown1ForPowerdown<'a>{
	pub cell: &'a Powerdown,
}

pub static EPOWERDOWN1FORPOWERDOWN: EPowerdown1ForPowerdown = EPowerdown1ForPowerdown {
	cell: &POWERDOWN,
};

pub struct EPowerdown2ForPowerdown<'a>{
	pub cell: &'a Powerdown,
}

pub static EPOWERDOWN2FORPOWERDOWN: EPowerdown2ForPowerdown = EPowerdown2ForPowerdown {
	cell: &POWERDOWN,
};

impl SPowerdown1 for EPowerdown1ForPowerdown<'_>{

	#[inline]
	fn powerdown<'a>(&self, motor: &Option<&'a mut pup_motor_t>) {
		let mut cell_ref = self.cell.get_cell_ref();

	}
}

impl SPowerdown2 for EPowerdown2ForPowerdown<'_>{

	#[inline]
	fn powerdown<'a>(&self, ult: &Option<&'a mut pup_ultrasonic_sensor_t>) {
		let mut cell_ref = self.cell.get_cell_ref();

	}
}

impl Powerdown {
	#[inline]
	pub fn get_cell_ref(&self) -> () {
		()
	}
}

