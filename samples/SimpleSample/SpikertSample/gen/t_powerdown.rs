use crate::{s_powerdown::*};

pub struct TPowerdown
{
}

pub struct EPowerdown1ForTPowerdown<'a>{
	pub cell: &'a TPowerdown,
}

pub struct EPowerdown2ForTPowerdown<'a>{
	pub cell: &'a TPowerdown,
}

pub static POWERDOWN: TPowerdown = TPowerdown {
};

pub static EPOWERDOWN1FORPOWERDOWN: EPowerdown1ForTPowerdown = EPowerdown1ForTPowerdown {
	cell: &POWERDOWN,
};

pub static EPOWERDOWN2FORPOWERDOWN: EPowerdown2ForTPowerdown = EPowerdown2ForTPowerdown {
	cell: &POWERDOWN,
};

