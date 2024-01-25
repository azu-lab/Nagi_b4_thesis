use crate::{s_task::*, t_task_rs::*};

pub struct TTaskbody<'a, T>
where
	T: STask,
{
	pub c_task: &'a T,
}

pub struct ETaskbodyForTTaskbody<'a>{
	pub cell: &'a TTaskbody<'a, ETaskForTTaskRs<'a>>,
}

pub static TASKBODY: TTaskbody<ETaskForTTaskRs> = TTaskbody {
	c_task: &ETASKFORTASK_SLEEP,
};

pub static ETASKBODYFORTASKBODY: ETaskbodyForTTaskbody = ETaskbodyForTTaskbody {
	cell: &TASKBODY,
};

impl<T: STask> TTaskbody<'_, T> {
	pub fn get_cell_ref(&self) -> &T {
		&self.c_task
	}
}