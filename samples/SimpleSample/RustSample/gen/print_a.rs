use spin::Mutex;
use crate::{s_sample::*, s_sample2::*, calcu::*};

pub struct PrintA<'a, T>
where
	T: SSample,
{
	pub c_calculate: &'a T,
	pub attribute: i16,
	pub variable: &'a Mutex<PrintAVar>,
}

pub struct PrintAVar {
	pub variable: i16,
}

pub static PRINTA: PrintA<ECalculate> = PrintA {
	c_calculate: &ECALCULATE,
	attribute: 1,
	variable: &PRINTAVAR,
};

pub static PRINTAVAR: Mutex<PrintAVar> = Mutex::new(PrintAVar {
	variable: 0,
});

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

impl SSample for EPrint<'_, ECalculate> {

	fn print(&self, varin: &i8, varout: &mut i32, varout2: &mut i32) {

		let cell_ref = self.cell.get_cell_ref();

	}

}

impl SSample2 for EPrint2<'_, ECalculate> {

	fn print(&self, buf_in: &heapless::String<256>, buf_out: &mut heapless::String<256>) {

		let cell_ref = self.cell.get_cell_ref();

	}

}

impl<T: SSample> PrintA<'_, T> {
	pub fn get_cell_ref(&self) -> (&T, &attribute, &Mutex<PrintAVar>) {
		(&self.c_calculate, &self.attribute, self.variable)
	}
}

