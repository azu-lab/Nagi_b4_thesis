use crate::{s_task_body::*, s_sensor::*, sensor::*, s_motor::*, motor::*};

pub struct Taskbody<'a, T, U>
where
	T: SSensor,
	U: SMotor,
{
	pub c_sensor: &'a T,
	pub c_motor: &'a U,
}

pub static TASKBODY: Taskbody<ESensorForSensor, EMotorForMotor> = Taskbody {
	c_sensor: &ESENSORFORSENSOR,
	c_motor: &EMOTORFORMOTOR,
};

pub struct ETaskbodyForTaskbody<'a>{
	pub cell: &'a Taskbody<'a, ESensorForSensor<'a>, EMotorForMotor<'a>>,
}

pub static ETASKBODYFORTASKBODY: ETaskbodyForTaskbody = ETaskbodyForTaskbody {
	cell: &TASKBODY,
};

impl STaskBody for ETaskbodyForTaskbody<'_>{

	#[inline]
	fn main(&self) {
		let mut cell_ref = self.cell.get_cell_ref();

	}
}

impl<T: SSensor, U: SMotor> Taskbody<'_, T, U> {
	#[inline]
	pub fn get_cell_ref(&self) -> (&T, &U) {
		(&self.c_sensor, &self.c_motor)
	}
}

