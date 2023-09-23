use crate::{s_sample::*};

pub struct PrintA {
	pub attribute: i16,
}

pub const PRINTA: PrintA = PrintA {
	attribute: 1,
};
pub struct PrintA<'a, T>
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


impl<'a, T> SSample<ClientPrint<'a, T>> for PrintA {

	fn print(&self, var: &mut ClientPrint<T>, varin: &i8, varout: &mut unknown, varout2: &mut unknown){

	}

}