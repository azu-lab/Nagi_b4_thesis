use crate::{s_binary_search::*, s_compare::*, compare::*};

pub struct Binarysearch<'a, T>
where
	T: SCompare,
{
	pub c_compare: &'a T,
	pub array: [i32; 5],
}

pub static BINARYSEARCH: Binarysearch<ECompareForCompare> = Binarysearch {
	c_compare: &ECOMPAREFORCOMPARE,
	array: [1, 2, 3, 4, 5],
};

pub struct EBinarySearchForBinarysearch<'a>{
	pub cell: &'a Binarysearch<'a, ECompareForCompare<'a>>,
}

pub static EBINARYSEARCHFORBINARYSEARCH: EBinarySearchForBinarysearch = EBinarySearchForBinarysearch {
	cell: &BINARYSEARCH,
};

impl<T: SCompare> Binarysearch<'_, T> {
	#[inline]
	pub fn get_cell_ref(&self) -> (&T, &[i32; 5]) {
		(&self.c_compare, &self.array)
	}
}

