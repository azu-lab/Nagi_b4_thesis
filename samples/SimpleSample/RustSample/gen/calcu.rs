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

pub struct ECalculateForCalcu<'a>{
	pub cell: &'a Calcu<'a>,
}

pub static ECALCULATEFORCALCU: ECalculateForCalcu = ECalculateForCalcu {
	cell: &CALCU,
};

impl SSample for ECalculateForCalcu<'_> {

	fn print(&self, varin: &i8, varout: &mut , varout2: &mut ) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn test(&self, test_in: &heapless::String<256>, test_out: &mut i-1) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

}

impl Calcu<'_> {
	pub fn get_cell_ref(&self) -> (&i32, &Mutex<CalcuVar>) {
		(&self.attribute, self.variable)
	}
}

