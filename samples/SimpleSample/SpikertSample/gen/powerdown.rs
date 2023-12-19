use crate::{s_powerdown::*};

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

impl Powerdown {
	#[inline]
	pub fn get_cell_ref(&self) -> () {
		()
	}
}

