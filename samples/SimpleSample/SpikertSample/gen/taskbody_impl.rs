use crate::{taskbody::*, s_task_body::*, s_sensor::*, s_motor::*};

impl STaskBody for ETaskbodyForTaskbody<'_>{

	#[inline]
	fn main(&self) {
		let cell_ref = self.cell.get_cell_ref();

	}
}

