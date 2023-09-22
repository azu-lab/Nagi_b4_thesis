use crate::{s_sample::*, client_print::*};

pub struct PrintA {
	pub attribute: i16,
}

pub const PRINTA: PrintA = PrintA {
	attribute: 1,
};

impl<'a, T> SSample<ClientPrint<'a, T>> for PrintA {

	fn print(&self, var: &mut ClientPrint<T>, varin: &i8, varsend: mut unknown, varout: &mut unknown, varout2: &mut unknown){

	}

}