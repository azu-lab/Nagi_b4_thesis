use crate::{t_powerdown::*, s_powerdown::*};

impl SPowerdown for EPowerdown1ForTPowerdown<'_>{

	#[inline]
	fn powerdown(&self, error: &pbio_error_t) {

	}
}

impl SPowerdown for EPowerdown2ForTPowerdown<'_>{

	#[inline]
	fn powerdown(&self, error: &pbio_error_t) {

	}
}

