use crate::{s_powerdown::*, t_powerdown::*};

pub struct TSensor<'a, T>
where
	T: SPowerdown,
{
	pub c_powerdown: &'a T,
	pub ult_ref: pup_ultrasonic_sensor_t,
}

pub struct ESensorForTSensor<'a>{
	pub cell: &'a TSensor<'a, EPowerdown2ForTPowerdown<'a>>,
}

pub static SENSOR: TSensor<EPowerdown2ForTPowerdown> = TSensor {
	c_powerdown: &EPOWERDOWN2FORPOWERDOWN,
	ult_ref: unsafe { pup_ultrasonic_sensor_get_device(pbio_port_id_t::PBIO_PORT_ID_B) },
};

pub static ESENSORFORSENSOR: ESensorForTSensor = ESensorForTSensor {
	cell: &SENSOR,
};

impl<T: SPowerdown> TSensor<'_, T> {
	#[inline]
	pub fn get_cell_ref(&self) -> (&T, &pup_ultrasonic_sensor_t) {
		(&self.c_powerdown, &self.ult_ref)
	}
}