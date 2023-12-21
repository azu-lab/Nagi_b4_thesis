use crate::{compare::*, s_compare::*};

impl SCompare for ECompareForCompare<'_>{

	#[inline]
	fn cmp(&self, value: &i32, key: &i32, left: &mut i32, right: &mut i32, mind: &i32) {
		let cell_ref = self.cell.get_cell_ref();

	}
}

