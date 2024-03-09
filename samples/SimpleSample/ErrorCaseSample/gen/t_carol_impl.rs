use crate::{t_carol::*, s_hello::*};

impl SHello for ECarolForTCarol<'_>{

	fn Hello(&self) {
		let cell_ref = self.cell.get_cell_ref();

	}
}

