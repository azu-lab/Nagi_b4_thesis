use spin::Mutex;
use crate::{s_powerdown::*, t_powerdown::*, s_motor::*};

pub struct TMotor<'a, T>
where
	T: SPowerdown,
{
	pub c_powerdown: &'a T,
	pub port: pbio_port_id_t,
	pub variable: &'a Mutex<TMotorVar<'a>>,
}

pub struct TMotorVar<'a>{
	pub motor: Option<&'a mut pup_motor_t>,
}

pub struct EMotorForTMotor<'a>{
	pub cell: &'a TMotor<'a, EPowerdown1ForTPowerdown<'a>>,
}

pub static MOTOR: TMotor<EPowerdown1ForPowerdown> = TMotor {
	c_powerdown: &EPOWERDOWN1FORPOWERDOWN,
	port: pbio_port_id_t::PBIO_PORT_ID_A,
	variable: &MOTORVAR,
};

pub static MOTORVAR: Mutex<MotorVar> = Mutex::new(MotorVar {
	motor: None,
});

pub static EMOTORFORMOTOR: EMotorForTMotor = EMotorForTMotor {
	cell: &MOTOR,
};

impl<'a, T: SPowerdown> TMotor<'a, T> {
	#[inline]
	pub fn get_cell_ref<'a>(&self) -> (&T, &pbio_port_id_t, &Mutex<TMotorVar<'a>>) {
		(&self.c_powerdown, &self.port, self.variable)
	}
}

