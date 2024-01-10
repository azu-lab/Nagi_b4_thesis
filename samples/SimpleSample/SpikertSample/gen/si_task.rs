use spin::Mutex;
use itron::abi::*;
use itron::task::TaskRef;
pub trait SiTask {
	#[inline]
	fn activate(&self)-> ER;
	#[inline]
	fn wakeup(&self)-> ER;
	#[inline]
	fn releaseWait(&self)-> ER;
}
