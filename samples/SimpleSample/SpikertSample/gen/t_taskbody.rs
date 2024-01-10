use crate::{s_task_body::*, s_sensor::*, t_sensor::*, s_motor::*, t_motor::*};

pub struct TTaskbody<'a, T, U>
where
	T: SSensor,
	U: SMotor,
{
	pub c_sensor: &'a T,
	pub c_motor: &'a U,
}

pub struct ETaskbodyForTTaskbody<'a>{
	pub cell: &'a TTaskbody<'a, ESensorForTSensor<'a>, EMotorForTMotor<'a>>,
}

pub static TASKBODY: TTaskbody<ESensorForSensor, EMotorForMotor> = TTaskbody {
	c_sensor: &ESENSORFORSENSOR,
	c_motor: &EMOTORFORMOTOR,
};

pub static ETASKBODYFORTASKBODY: ETaskbodyForTTaskbody = ETaskbodyForTTaskbody {
	cell: &TASKBODY,
};

impl<T: SSensor, U: SMotor> TTaskbody<'_, T, U> {
	#[inline]
	pub fn get_cell_ref(&self) -> (&T, &U) {
		(&self.c_sensor, &self.c_motor)
	}
}

