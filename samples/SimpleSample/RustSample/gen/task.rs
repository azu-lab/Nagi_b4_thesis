mod s_kernel;
mod si_kernel;
mod si_notification_handler;
mod s_task_body;
mod s_task;
mod si_task;
mod s_semaphore;
mod si_semaphore;
mod s_eventflag;
mod si_eventflag;
mod s_dataqueue;
mod si_dataqueue;
mod s_priority_dataqueue;
mod si_priority_dataqueue;
mod s_mutex;
mod s_fixed_size_memory_pool;
mod si_handler_body;
mod s_cyclic;
mod s_alarm;
mod si_alarm;
mod s_interrupt_request;
mod si_cpu_exception_handler_body;
mod s_routine_body;
mod client_kernel;
mod client_kernel;
mod task;
mod client_task;
mod client_task;
mod client_task;
mod client_task;
mod client_semaphore;
mod client_semaphore;
mod client_semaphore;
mod client_eventflag;
mod client_eventflag;
mod client_eventflag;
mod client_dataqueue;
mod client_dataqueue;
mod client_dataqueue;
mod client_priority_dataqueue;
mod client_priority_dataqueue;
mod client_mutex;
mod client_fixed_size_memory_pool;
mod client_time_event_handler;
mod client_cyclic_notifier;
mod client_alarm_notifier;
mod client_alarm_notifier;
mod client_interrupt_request;
mod print_a;
mod client_print;
use crate::{s_task::*, si_task::*, s_task_body::*, print_a::*, si_notification_handler::*};

pub struct Task<'a, T>
where
	T: STaskBody,
{
	pub c_task_body: &'a T,
	pub id: unknown,
	pub attribute: unknown,
	pub priority: unknown,
	pub stackSize: unknown,
}

pub static TASK: Task<EPrint> = Task {
	c_task_body: &EPRINTFORPRINTA,
	id: TSKID_$id$,
	attribute: TA_NULL,
	priority: ,
	stackSize: ,
};

pub struct ETaskForTask<'a>{
	pub cell: &'a Task<'a, EPrintForPrintA<'a>>,
}

pub static ETASKFORTASK: ETaskForTask = ETaskForTask {
	cell: &TASK,
};

pub struct EiTaskForTask<'a>{
	pub cell: &'a Task<'a, EPrintForPrintA<'a>>,
}

pub static EITASKFORTASK: EiTaskForTask = EiTaskForTask {
	cell: &TASK,
};

pub struct EiActivateNotificationHandlerForTask<'a>{
	pub cell: &'a Task<'a, EPrintForPrintA<'a>>,
}

pub static EIACTIVATENOTIFICATIONHANDLERFORTASK: EiActivateNotificationHandlerForTask = EiActivateNotificationHandlerForTask {
	cell: &TASK,
};

pub struct EiWakeUpNotificationHandlerForTask<'a>{
	pub cell: &'a Task<'a, EPrintForPrintA<'a>>,
}

pub static EIWAKEUPNOTIFICATIONHANDLERFORTASK: EiWakeUpNotificationHandlerForTask = EiWakeUpNotificationHandlerForTask {
	cell: &TASK,
};

impl STask for ETaskForTask<'_, EPrintForPrintA> {

	fn activate(&self) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn cancelActivate(&self) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn getTaskState(&self, p_tskstat: &mut ) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn changePriority(&self, priority: &unknown) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn getPriority(&self, p_priority: &mut ) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn refer(&self, pk_taskStatus: &mut ) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn wakeup(&self) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn cancelWakeup(&self) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn releaseWait(&self) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn suspend(&self) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn resume(&self) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn raiseTerminate(&self) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn terminate(&self) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

}

impl SiTask for EiTaskForTask<'_, EPrintForPrintA> {

	fn activate(&self) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn wakeup(&self) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

	fn releaseWait(&self) {

		let mut cell_ref = self.cell.get_cell_ref();

	}

}

impl SiNotificationHandler for EiActivateNotificationHandlerForTask<'_, EPrintForPrintA> {

}

impl SiNotificationHandler for EiWakeUpNotificationHandlerForTask<'_, EPrintForPrintA> {

}

impl<T: STaskBody> Task<'_, T> {
	pub fn get_cell_ref(&self) -> (&T, &unknown, &unknown, &unknown, &unknown, &Mutex<TaskVar>) {
		(&self.c_task_body, &self.id, &self.attribute, &self.priority, &self.stackSize, self.variable)
	}
}

