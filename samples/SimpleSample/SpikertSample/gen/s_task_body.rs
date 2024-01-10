use spin::Mutex;
pub trait STaskBody {
	#[inline]
	fn main(&self);
}
