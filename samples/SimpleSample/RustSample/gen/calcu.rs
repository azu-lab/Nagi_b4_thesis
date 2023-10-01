mod s_sample;
mod s_sample2;
mod sample;
mod print_a;
mod client_print;
mod client_print;
mod calcu;
mod client_calculate;
use crate::{s_sample::*, sample::*, print_a::*, client_print::*, calcu::*, client_calculate::*};

pub struct Calcu<'a>
{
	pub attribute: i32,
	pub variable: &'a mut CalcuVar,
}

pub struct CalcuVar {
	pub variable: i32,
}

pub static CALCU: Calcu = Calcu {
	attribute: 4,
	variable: &CALCUVAR,
};

pub static CALCUVAR: CalcuVar = CalcuVar {
	variable: 3,
};

impl SSample for ECalculate<'_> {

	fn print(&self, varin: &i8, varout: &mut i32, varout2: &mut i32) {

	}

}

pub struct ECalculate<'a>{
	pub cell: &'a Calcu<'a>,
}

pub static ECALCULATE: ECalculate = ECalculate {
	cell: &CALCU,
};

