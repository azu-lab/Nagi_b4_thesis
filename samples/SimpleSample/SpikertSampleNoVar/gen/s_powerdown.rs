use spin::Mutex;
pub trait SPowerdown {
	fn powerdown(&self, error: &pbio_error_t);
}
