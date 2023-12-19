pub trait SPowerdown {
	#[inline]
	fn powerdown(&self, error: &pbio_error_t);
}
