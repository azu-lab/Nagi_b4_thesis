use crate::{s_compare::*};

pub struct Compare
{
}

pub static COMPARE: Compare = Compare {
};

pub struct ECompareForCompare<'a>{
	pub cell: &'a Compare,
}

pub static ECOMPAREFORCOMPARE: ECompareForCompare = ECompareForCompare {
	cell: &COMPARE,
};

impl Compare {
	#[inline]
	pub fn get_cell_ref(&self) -> () {
		()
	}
}

