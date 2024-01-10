use spin::Mutex;
use itron::abi::*;
use itron::task::TaskRef;
pub trait STask {
	#[inline]
	fn activate(&self)-> ER;
	#[inline]
	fn cancelActivate(&self)-> ER_UINT;
	#[inline]
	fn getTaskState(&self, p_tskstat: &mut STAT)-> ER;
	#[inline]
	fn changePriority(&self, priority: &PRI)-> ER;
	#[inline]
	fn getPriority(&self, p_priority: &mut PRI)-> ER;
	#[inline]
	fn refer(&self, pk_taskStatus: &mut T_RTSK)-> ER;
	#[inline]
	fn wakeup(&self)-> ER;
	#[inline]
	fn cancelWakeup(&self)-> ER_UINT;
	#[inline]
	fn releaseWait(&self)-> ER;
	#[inline]
	fn suspend(&self)-> ER;
	#[inline]
	fn resume(&self)-> ER;
	#[inline]
	fn raiseTerminate(&self)-> ER;
	#[inline]
	fn terminate(&self)-> ER;
}
