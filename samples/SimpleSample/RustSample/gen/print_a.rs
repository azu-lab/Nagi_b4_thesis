use spin::Mutex;
use crate::{s_task_body::*, s_task::*, task::*};

pub struct PrintA<'a>
{
	pub c_task: &TaskRef,
	pub printattr: i32,
	pub variable: &'a Mutex<PrintAVar>,
}

pub struct PrintAVar {
	pub printvar: i32,
}

pub static PRINTA: PrintA = PrintA {
	c_task: &TASK
	printattr: 2,
	variable: &PRINTAVAR,
};

pub static PRINTAVAR: Mutex<PrintAVar> = Mutex::new(PrintAVar {
	printvar: 10,
});

pub struct EPrintForPrintA<'a>{
	pub cell: &'a PrintA<'a>,
}

pub static EPRINTFORPRINTA: EPrintForPrintA = EPrintForPrintA {
	cell: &PRINTA,
};

impl STaskBody for EPrintForPrintA<'_> {

	fn main(&self) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

}

impl PrintA<'_> {
	pub fn get_cell_ref(&self) -> (&T, &i32, &Mutex<PrintAVar>) {
		(&self.c_task, &self.printattr, self.variable)
	}
}

