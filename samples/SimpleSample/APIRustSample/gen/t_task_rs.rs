use crate::kernel_cfg::*;  //特別な生成部
use itron::abi::*;  //特別な生成部
use itron::task::TaskRef;  //特別な生成部
use core::num::NonZeroI32;  //特別な生成部
use crate::{s_task_body::*, t_taskbody::*, t_taskbody2::*};

pub struct TTaskRs<'a, T>
where
	T: STaskBody,
{
	pub c_task_body: &'a T,
	pub task_ref: TaskRef<'a>,  //特別な生成部
}

pub struct ETaskForTTaskRs<'a>{
	pub cell: &'a TTaskRs<'a, ETaskbodyForTTaskbody<'a>>,
}

pub struct EiTaskForTTaskRs<'a>{
	pub cell: &'a TTaskRs<'a, ETaskbodyForTTaskbody<'a>>,
}

pub struct EiActivateNotificationHandlerForTTaskRs<'a>{
	pub cell: &'a TTaskRs<'a, ETaskbodyForTTaskbody<'a>>,
}

pub struct EiWakeUpNotificationHandlerForTTaskRs<'a>{
	pub cell: &'a TTaskRs<'a, ETaskbodyForTTaskbody<'a>>,
}

pub struct ETaskForTTaskRs<'a>{
	pub cell: &'a TTaskRs<'a, ETaskbodyForTTaskbody2<'a>>,
}

pub struct EiTaskForTTaskRs<'a>{
	pub cell: &'a TTaskRs<'a, ETaskbodyForTTaskbody2<'a>>,
}

pub struct EiActivateNotificationHandlerForTTaskRs<'a>{
	pub cell: &'a TTaskRs<'a, ETaskbodyForTTaskbody2<'a>>,
}

pub struct EiWakeUpNotificationHandlerForTTaskRs<'a>{
	pub cell: &'a TTaskRs<'a, ETaskbodyForTTaskbody2<'a>>,
}

pub static TASK: TTaskRs<ETaskbodyForTTaskbody> = TTaskRs {
	c_task_body: &ETASKBODYFORTASKBODY,
	task_ref: unsafe{TaskRef::from_raw_nonnull(NonZeroI32::new(TSKID_1).unwrap())},
};

pub static ETASKFORTASK: ETaskForTTaskRs = ETaskForTTaskRs {
	cell: &TASK,
};

pub static EITASKFORTASK: EiTaskForTTaskRs = EiTaskForTTaskRs {
	cell: &TASK,
};

pub static EIACTIVATENOTIFICATIONHANDLERFORTASK: EiActivateNotificationHandlerForTTaskRs = EiActivateNotificationHandlerForTTaskRs {
	cell: &TASK,
};

pub static EIWAKEUPNOTIFICATIONHANDLERFORTASK: EiWakeUpNotificationHandlerForTTaskRs = EiWakeUpNotificationHandlerForTTaskRs {
	cell: &TASK,
};

pub static TASK_SLEEP: TTaskRs<ETaskbodyForTTaskbody2> = TTaskRs {
	c_task_body: &ETASKBODYFORTASKBODY,
	task_ref: unsafe{TaskRef::from_raw_nonnull(NonZeroI32::new(TSKID_2).unwrap())},
};

pub static ETASKFORTASK_SLEEP: ETaskForTTaskRs = ETaskForTTaskRs {
	cell: &TASK_SLEEP,
};

pub static EITASKFORTASK_SLEEP: EiTaskForTTaskRs = EiTaskForTTaskRs {
	cell: &TASK_SLEEP,
};

pub static EIACTIVATENOTIFICATIONHANDLERFORTASK_SLEEP: EiActivateNotificationHandlerForTTaskRs = EiActivateNotificationHandlerForTTaskRs {
	cell: &TASK_SLEEP,
};

pub static EIWAKEUPNOTIFICATIONHANDLERFORTASK_SLEEP: EiWakeUpNotificationHandlerForTTaskRs = EiWakeUpNotificationHandlerForTTaskRs {
	cell: &TASK_SLEEP,
};

impl<T: STaskBody> TTaskRs<'_, T> {
	#[inline]
	pub fn get_cell_ref(&self) -> (&T, &TaskRef) {
		(&self.c_task_body, &self.task_ref)
	}
}