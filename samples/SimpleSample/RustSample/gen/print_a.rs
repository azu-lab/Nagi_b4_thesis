mod s_sample;
mod s_sample2;
mod sample;
mod print_a;
mod client_print;
mod client_print;
mod calcu;
mod client_calculate;
use crate::{s_sample::*, s_sample2::*, calculate_des::*, sample::*, print_a::*, client_print::*, calcu::*, client_calculate::*};

pub struct PrintA<'a, T>
where
	T: SSample,
{
	pub c_calculate: &'a T,
	pub attribute: i16,
	pub variable: &'a mut PrintAVar,
}

pub struct PrintAVar {
	pub variable: i16,
}

pub static PRINTA: PrintA<ECalculate> = PrintA {
	c_calculate: &ECALCULATE,
	attribute: 1,
	variable: &PRINTAVAR,
};

pub static PRINTAVAR: PrintAVar = PrintAVar {
	variable: 0,
};

impl SSample for EPrint<'_, ECalculate> {

	fn print(&self, varin: &i8, varout: &mut i32, varout2: &mut i32) {

	}

}

impl SSample2 for EPrint2<'_, ECalculate> {

	fn print(&self) {

	}

}

pub struct EPrint<'a>{
	pub cell: &'a PrintA<'a, ECalculate<'a>>,
}

pub static EPRINT: EPrint = EPrint {
	cell: &PRINTA,
};

pub struct EPrint2<'a>{
	pub cell: &'a PrintA<'a, ECalculate<'a>>,
}

pub static EPRINT2: EPrint2 = EPrint2 {
	cell: &PRINTA,
};

