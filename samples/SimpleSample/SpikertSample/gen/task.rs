use crate::kernel_cfg::*;  //特別な生成部
use itron::abi::*;  //特別な生成部
use itron::task::TaskRef::*;  //特別な生成部
use crate::{s_task::*, si_task::*, s_task_body::*, taskbody::*, si_notification_handler::*};

pub struct Task<'a, T>
where
	T: STaskBody,
{
	pub c_task_body: &'a T,
	pub task_ref: TaskRef<'a>,  //特別な生成部
}

pub static TASK: Task<ETaskbody> = Task {
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

impl STask for ETaskForTask<'_, ETaskbodyForTaskbody<'_>> {

	fn activate(&self) -> ER{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn cancelActivate(&self) -> ER_UINT{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn getTaskState(&self, p_tskstat: &mut STAT) -> ER{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn changePriority(&self, priority: &PRI) -> ER{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn getPriority(&self, p_priority: &mut PRI) -> ER{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn refer(&self, pk_taskStatus: &mut T_RTSK) -> ER{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn wakeup(&self) -> ER{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn cancelWakeup(&self) -> ER_UINT{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn releaseWait(&self) -> ER{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn suspend(&self) -> ER{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn resume(&self) -> ER{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn raiseTerminate(&self) -> ER{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn terminate(&self) -> ER{

		let mut cell_ref = self.cell.get_cell_ref();

	}

}

impl SiTask for EiTaskForTask<'_, ETaskbodyForTaskbody<'_>> {

	fn activate(&self) -> ER{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn wakeup(&self) -> ER{

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn releaseWait(&self) -> ER{

		let mut cell_ref = self.cell.get_cell_ref();

	}

}

impl SiNotificationHandler for EiActivateNotificationHandlerForTask<'_, ETaskbodyForTaskbody<'_>> {

}

impl SiNotificationHandler for EiWakeUpNotificationHandlerForTask<'_, ETaskbodyForTaskbody<'_>> {

}

impl<T: STaskBody> Task<'_, T> {
	pub fn get_cell_ref(&self) -> (&T, &TaskRef, &Mutex<TaskVar>) {
		(&self.c_task_body, &self.task_ref, self.variable)
	}
}

