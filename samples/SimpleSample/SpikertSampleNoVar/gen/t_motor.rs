use crate::{s_powerdown::*, t_powerdown::*};

pub struct TMotor<'a, T>
where
	T: SPowerdown,
{
	pub c_powerdown: &'a T,
	pub motor_ref: pup_motor_t,
}

pub struct EMotorForTMotor<'a>{
	pub cell: &'a TMotor<'a, EPowerdown1ForTPowerdown<'a>>,
}

pub static MOTOR: TMotor<EPowerdown1ForTPowerdown> = TMotor {
	c_powerdown: &EPOWERDOWN1FORPOWERDOWN,
	motor_ref: unsafe{ pup_motor_get_device(pbio_port_id_t::PBIO_PORT_ID_A) },
};

pub static EMOTORFORMOTOR: EMotorForTMotor = EMotorForTMotor {
	cell: &MOTOR,
};

impl<T: SPowerdown> TMotor<'_, T> {
	#[inline]
	pub fn get_cell_ref(&self) -> (&T, &pup_motor_t) {
		(&self.c_powerdown, &self.motor_ref)
	}
}