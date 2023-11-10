use spin::Mutex;
use crate::{s_task_body::*};

pub struct PrintA<'a>
{
	pub printattr: i32,
	pub variable: &'a Mutex<PrintAVar>,
}

pub struct PrintAVar {
	pub printvar: i32,
}

pub static PRINTA: PrintA = PrintA {
	printattr: 1,
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

	fn main(&self) -> void{

		let mut cell_ref = self.cell.get_cell_ref();

	}

}

impl PrintA<'_> {
	pub fn get_cell_ref(&self) -> (&i32, &Mutex<PrintAVar>) {
		(&self.printattr, self.variable)
	}
}

