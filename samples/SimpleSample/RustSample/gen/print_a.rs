use spin::Mutex;
use crate::{s_task_body::*, s_task::*, task::*};

pub struct PrintA<'a, T>
where
	T: STask,
{
	pub c_task: &'a T,
	pub printattr: i32,
	pub variable: &'a Mutex<PrintAVar>,
}

pub struct PrintAVar {
	pub printvar: i32,
}

pub static PRINTA: PrintA<ETask> = PrintA {
	c_task: &ETASKFORTASK,
	printattr: 2,
	variable: &PRINTAVAR,
};

pub static PRINTAVAR: Mutex<PrintAVar> = Mutex::new(PrintAVar {
	printvar: 10,
});

pub struct EPrintForPrintA<'a>{
	pub cell: &'a PrintA<'a, ETaskForTask<'a>>,
}

pub static EPRINTFORPRINTA: EPrintForPrintA = EPrintForPrintA {
	cell: &PRINTA,
};

impl STaskBody for EPrintForPrintA<'_, ETaskForTask> {

	fn main(&self) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

}

impl<T: STask> PrintA<'_, T> {
	pub fn get_cell_ref(&self) -> (&T, &i32, &Mutex<PrintAVar>) {
		(&self.c_task, &self.printattr, self.variable)
	}
}

