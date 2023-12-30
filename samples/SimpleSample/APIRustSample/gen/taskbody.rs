use crate::{s_task_body::*, s_task::*, task::*};

pub struct Taskbody<'a, T>
where
	T: STask,
{
	pub c_task: &'a T,
}

pub static TASKBODY: Taskbody<ETaskForTask> = Taskbody {
	c_task: &ETASKFORTASK,
};

pub struct ETaskbodyForTaskbody<'a>{
	pub cell: &'a Taskbody<'a, ETaskForTask<'a>>,
}

pub static ETASKBODYFORTASKBODY: ETaskbodyForTaskbody = ETaskbodyForTaskbody {
	cell: &TASKBODY,
};

impl<T: STask> Taskbody<'_, T> {
	#[inline]
	pub fn get_cell_ref(&self) -> (&T) {
		(&self.c_task)
	}
}

