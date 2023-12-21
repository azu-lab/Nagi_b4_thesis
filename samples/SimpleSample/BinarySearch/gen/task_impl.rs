use crate::{task::*, s_task::*, si_task::*, s_task_body::*, si_notification_handler::*};

impl STask for ETaskForTask<'_>{

	#[inline]
	fn activate(&self) -> ER{
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn cancelActivate(&self) -> ER_UINT{
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn getTaskState(&self, p_tskstat: &mut STAT) -> ER{
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn changePriority(&self, priority: &PRI) -> ER{
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn getPriority(&self, p_priority: &mut PRI) -> ER{
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn refer(&self, pk_taskStatus: &mut T_RTSK) -> ER{
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn wakeup(&self) -> ER{
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn cancelWakeup(&self) -> ER_UINT{
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn releaseWait(&self) -> ER{
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn suspend(&self) -> ER{
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn resume(&self) -> ER{
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn raiseTerminate(&self) -> ER{
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn terminate(&self) -> ER{
		let cell_ref = self.cell.get_cell_ref();

	}
}

impl SiTask for EiTaskForTask<'_>{

	#[inline]
	fn activate(&self) -> ER{
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn wakeup(&self) -> ER{
		let cell_ref = self.cell.get_cell_ref();

	}
	#[inline]
	fn releaseWait(&self) -> ER{
		let cell_ref = self.cell.get_cell_ref();

	}
}

impl SiNotificationHandler for EiActivateNotificationHandlerForTask<'_>{

}

impl SiNotificationHandler for EiWakeUpNotificationHandlerForTask<'_>{

}

