use spin::Mutex;
use crate::{s_powerdown1::*, powerdown::*, s_motor::*};

pub struct Motor<'a, T>
where
	T: SPowerdown1,
{
	pub c_powerdown: &'a T,
	pub port: pbio_port_id_t,
	pub variable: &'a Mutex<MotorVar<'a>>,
}

pub struct MotorVar<'a>{
	pub motor: Option<&'a mut pup_motor_t>,
}

pub static MOTOR: Motor<EPowerdown1> = Motor {
	c_powerdown: &EPOWERDOWN1FORPOWERDOWN,
	port: PBIO_PORT_ID_A,
	variable: &MOTORVAR,
};

pub static MOTORVAR: Mutex<MotorVar> = Mutex::new(MotorVar {
	motor: None,
});

pub struct EMotorForMotor<'a>{
	pub cell: &'a Motor<'a, EPowerdown1ForPowerdown<'a>>,
}

pub static EMOTORFORMOTOR: EMotorForMotor = EMotorForMotor {
	cell: &MOTOR,
};

impl SMotor for EMotorForMotor<'_, EPowerdown1ForPowerdown> {

	fn set_motor_ref(&self) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn setup(&self, positive_direction: &pup_direction_t, reset_count: &bool) -> pbio_error_t{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn set_speed(&self, speed: &i32) -> pbio_error_t{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn stop(&self) -> pbio_error_t{

		let mut cell_ref = self.cell.get_cell_ref();

	}

}

impl<T: SPowerdown1> Motor<'_, T> {
	pub fn get_cell_ref(&self) -> (&T, &pbio_port_id_t, &Mutex<MotorVar>) {
		(&self.c_powerdown, &self.port, self.variable)
	}
}

