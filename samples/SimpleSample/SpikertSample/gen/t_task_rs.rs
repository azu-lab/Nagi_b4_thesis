use crate::kernel_cfg::*;  //特別な生成部
use itron::abi::*;  //特別な生成部
use itron::task::TaskRef;  //特別な生成部
use core::num::NonZeroI32;  //特別な生成部
use crate::{s_task::*, si_task::*, s_task_body::*, t_taskbody::*, si_notification_handler::*};

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

pub static TASK: TTaskRs<ETaskbodyForTaskbody> = TTaskRs {
	c_task_body: &ETASKBODYFORTASKBODY,
	task_ref: unsafe{TaskRef::from_raw_nonnull(NonZeroI32::new(TASK1).unwrap())},
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

impl<T: STaskBody> TTaskRs<'_, T> {
	#[inline]
	pub fn get_cell_ref(&self) -> (&T, &TaskRef) {
		(&self.c_task_body, &self.task_ref)
	}
}

