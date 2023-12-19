use crate::{powerdown::*, s_powerdown::*};

impl SPowerdown for EPowerdown1ForPowerdown<'_>{

	#[inline]
	fn powerdown(&self, error: &pbio_error_t) {
		let cell_ref = self.cell.get_cell_ref();

	}
}

impl SPowerdown for EPowerdown2ForPowerdown<'_>{

	#[inline]
	fn powerdown(&self, error: &pbio_error_t) {
		let cell_ref = self.cell.get_cell_ref();

	}
}

