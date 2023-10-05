use spin::Mutex;
use crate::{s_sample::*};

pub struct Calcu<'a>
{
	pub attribute: i32,
	pub variable: &'a Mutex<CalcuVar>,
}

pub struct CalcuVar {
	pub variable: i32,
}

pub static CALCU: Calcu = Calcu {
	attribute: 4,
	variable: &CALCUVAR,
};

pub static CALCUVAR: Mutex<CalcuVar> = Mutex::new(CalcuVar {
	variable: 3,
});

pub struct ECalculate<'a>{
	pub cell: &'a Calcu<'a>,
}

pub static ECALCULATE: ECalculate = ECalculate {
	cell: &CALCU,
};

impl SSample for ECalculate<'_> {

	fn print(&self, varin: &i8, varout: &mut i32, varout2: &mut i32) {

		let cell_ref = self.cell.get_cell_ref();

	}

}

impl Calcu<'_> {
	pub fn get_cell_ref(&self) -> (&attribute, &Mutex<CalcuVar>) {
		(&self.attribute, self.variable)
	}
}

