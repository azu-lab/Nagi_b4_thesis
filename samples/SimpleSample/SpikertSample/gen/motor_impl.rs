use spin::Mutex;
use crate::{motor::*, s_powerdown::*, s_motor::*};

impl SMotor for EMotorForTMotor<'_>{

	#[inline]
	fn set_motor_ref(&self) {
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn setup(&self, positive_direction: &pup_direction_t, reset_count: &bool) {
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn set_speed(&self, speed: &i32) {
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn stop(&self) {
		let cell_ref = self.cell.get_cell_ref();

	}
}

