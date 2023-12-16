use spin::Mutex;
use crate::{s_powerdown2::*, powerdown::*, s_sensor::*};

pub struct Sensor<'a, T>
where
	T: SPowerdown2,
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

impl SSensor for ESensorForSensor<'_>{

	#[inline]
	fn set_device_ref(&self) {
		let mut cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn get_distance(&self, distance: &mut i32) {
		let mut cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn light_on(&self) -> pbio_error_t{
		let mut cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn light_set(&self, bv1: &i32, bv2: &i32, bv3: &i32, bv4: &i32) -> pbio_error_t{
		let mut cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn light_off(&self) -> pbio_error_t{
		let mut cell_ref = self.cell.get_cell_ref();

	}
}

impl<'a, T: SPowerdown2> Sensor<'a, T> {
	#[inline]
	pub fn get_cell_ref<'a>(&self) -> (&T, &pbio_port_id_t, &Mutex<SensorVar<'a>>) {
		(&self.c_powerdown, &self.port, self.variable)
	}
}

