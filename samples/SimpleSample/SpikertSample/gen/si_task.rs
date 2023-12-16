pub trait SiTask {
	#[inline]
	fn activate(&self)-> ER;
	#[inline]
	fn wakeup(&self)-> ER;
	#[inline]
	fn releaseWait(&self)-> ER;
}
