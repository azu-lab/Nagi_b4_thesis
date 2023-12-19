use spin::Mutex;
use crate::{s_powerdown::*, powerdown::*, s_sensor::*};

pub struct Sensor<'a, T>
where
	T: SPowerdown,
{
	pub c_powerdown: &'a T,
	pub port: pbio_port_id_t,
	pub variable: &'a Mutex<SensorVar<'a>>,
}

pub struct SensorVar<'a>{
	pub ult: Option<&'a mut pup_ultrasonic_sensor_t>,
}

pub static SENSOR: Sensor<EPowerdown2ForPowerdown> = Sensor {
	c_powerdown: &EPOWERDOWN2FORPOWERDOWN,
	port: pbio_port_id_t::PBIO_PORT_ID_B,
	variable: &SENSORVAR,
};

pub static SENSORVAR: Mutex<SensorVar> = Mutex::new(SensorVar {
	ult: None,
});

pub struct ESensorForSensor<'a>{
	pub cell: &'a Sensor<'a, EPowerdown2ForPowerdown<'a>>,
}

pub static ESENSORFORSENSOR: ESensorForSensor = ESensorForSensor {
	cell: &SENSOR,
};

impl<'a, T: SPowerdown> Sensor<'a, T> {
	#[inline]
	pub fn get_cell_ref<'a>(&self) -> (&T, &pbio_port_id_t, &Mutex<SensorVar<'a>>) {
		(&self.c_powerdown, &self.port, self.variable)
	}
}

