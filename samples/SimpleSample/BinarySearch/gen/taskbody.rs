use crate::{s_task_body::*, s_binary_search::*, binarysearch::*};

pub struct Taskbody<'a, T>
where
	T: SBinarySearch,
{
	pub c_binary_search: &'a T,
	pub key: i32,
}

pub static TASKBODY: Taskbody<EBinarySearchForBinarysearch> = Taskbody {
	c_binary_search: &EBINARYSEARCHFORBINARYSEARCH,
	key: 77,
};

pub struct ETaskbodyForTaskbody<'a>{
	pub cell: &'a Taskbody<'a, EBinarySearchForBinarysearch<'a>>,
}

pub static ETASKBODYFORTASKBODY: ETaskbodyForTaskbody = ETaskbodyForTaskbody {
	cell: &TASKBODY,
};

impl<T: SBinarySearch> Taskbody<'_, T> {
	#[inline]
	pub fn get_cell_ref(&self) -> (&T, &i32) {
		(&self.c_binary_search, &self.key)
	}
}

