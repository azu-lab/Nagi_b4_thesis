use crate::{s_task::*, t_task_rs::*};

pub struct TTaskbody2<'a, T>
where
	T: STask,
{
	pub c_task: &'a T,
}

pub struct ETaskbodyForTTaskbody2<'a>{
	pub cell: &'a TTaskbody2<'a, ETaskForTTaskRs<'a>>,
}

pub static TASKBODY2: TTaskbody2<ETaskForTTaskRs> = TTaskbody2 {
	c_task: &ETASKFORTASK,
};

pub static ETASKBODYFORTASKBODY2: ETaskbodyForTTaskbody2 = ETaskbodyForTTaskbody2 {
	cell: &TASKBODY2,
};

impl<T: STask> TTaskbody2<'_, T> {
	pub fn get_cell_ref(&self) -> &T {
		&self.c_task
	}
}