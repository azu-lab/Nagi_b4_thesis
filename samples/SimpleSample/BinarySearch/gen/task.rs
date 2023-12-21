use crate::kernel_cfg::*;  //特別な生成部
use itron::abi::*;  //特別な生成部
use itron::task::TaskRef::*;  //特別な生成部
use core::num::NonZeroI32;  //特別な生成部
use crate::{s_task::*, si_task::*, s_task_body::*, taskbody::*, si_notification_handler::*};

pub struct Task<'a, T>
where
	T: STaskBody,
{
	pub c_task_body: &'a T,
	pub task_ref: TaskRef<'a>,  //特別な生成部
}

pub static TASK: Task<ETaskbodyForTaskbody> = Task {
	c_task_body: &ETASKBODYFORTASKBODY,
	task_ref: unsafe{TaskRef::from_raw_nonnull(NonZeroI32::new(TASK1).unwrap())},
};

pub struct ETaskForTask<'a>{
	pub cell: &'a Task<'a, ETaskbodyForTaskbody<'a>>,
}

pub static ETASKFORTASK: ETaskForTask = ETaskForTask {
	cell: &TASK,
};

pub struct EiTaskForTask<'a>{
	pub cell: &'a Task<'a, ETaskbodyForTaskbody<'a>>,
}

pub static EITASKFORTASK: EiTaskForTask = EiTaskForTask {
	cell: &TASK,
};

pub struct EiActivateNotificationHandlerForTask<'a>{
	pub cell: &'a Task<'a, ETaskbodyForTaskbody<'a>>,
}

pub static EIACTIVATENOTIFICATIONHANDLERFORTASK: EiActivateNotificationHandlerForTask = EiActivateNotificationHandlerForTask {
	cell: &TASK,
};

pub struct EiWakeUpNotificationHandlerForTask<'a>{
	pub cell: &'a Task<'a, ETaskbodyForTaskbody<'a>>,
}

pub static EIWAKEUPNOTIFICATIONHANDLERFORTASK: EiWakeUpNotificationHandlerForTask = EiWakeUpNotificationHandlerForTask {
	cell: &TASK,
};

impl<T: STaskBody> Task<'_, T> {
	#[inline]
	pub fn get_cell_ref(&self) -> (&T, &TaskRef) {
		(&self.c_task_body, &self.task_ref)
	}
}

