mod s_sample;
mod s_sample2;
mod sample;
mod print_a;
mod client_print;
mod client_print;
use crate::{s_sample::*, s_sample2::*, sample::*, print_a::*, client_print::*};

pub struct PrintA<'a>
{
	pub attribute: i16,
	variable: &'a mut PrintAVar,
}

pub struct PrintAVar {
	variable: i16,
}

pub static PRINTA: PrintA = PrintA {
	attribute: 1,
	variable: &PRINTAVAR,
};

pub static PRINTAVAR: PrintAVar = PrintAVar {
	variable: 0,
};

impl SSample for PrintA<'_> {

	fn print( &self, varin: &i8, varout: &mut unknown, varout2: &mut unknown) {

	}

}

impl SSample2 for PrintA<'_> {

	fn print( &self) {

	}

}

