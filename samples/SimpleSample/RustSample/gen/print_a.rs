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
	c_calculate: &ECALCULATEFORCALCU,
	attribute: 1,
	variable: &PRINTAVAR,
};

pub static PRINTAVAR: Mutex<PrintAVar> = Mutex::new(PrintAVar {
	variable: 0,
});

pub struct EPrintForPrintA<'a>{
	pub cell: &'a PrintA<'a, ECalculateForCalcu<'a>>,
}

pub static EPRINTFORPRINTA: EPrintForPrintA = EPrintForPrintA {
	cell: &PRINTA,
};

pub struct EPrint2ForPrintA<'a>{
	pub cell: &'a PrintA<'a, ECalculateForCalcu<'a>>,
}

pub static EPRINT2FORPRINTA: EPrint2ForPrintA = EPrint2ForPrintA {
	cell: &PRINTA,
};

impl SSample for EPrintForPrintA<'_, ECalculateForCalcu> {

	fn print(&self, varin: &i8, varout: &mut i32, varout2: &mut i32) {

		let cell_ref = self.cell.get_cell_ref();

	}

}

impl SSample2 for EPrint2ForPrintA<'_, ECalculateForCalcu> {

	fn print(&self, buf_in: &heapless::String<256>, buf_out: &mut heapless::String<256>) {

		let cell_ref = self.cell.get_cell_ref();

	}

}

impl<T: SSample> PrintA<'_, T> {
	pub fn get_cell_ref(&self) -> (&T, &attribute, &Mutex<PrintAVar>) {
		(&self.c_calculate, &self.attribute, self.variable)
	}
}

