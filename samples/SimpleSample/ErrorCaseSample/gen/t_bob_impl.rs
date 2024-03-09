use crate::{t_bob::*, s_hello::*};

impl SHello for EBobForTBob<'_>{

	fn Hello(&self) {
		let cell_ref = self.cell.get_cell_ref();

	}
}

