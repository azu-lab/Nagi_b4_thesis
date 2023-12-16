pub trait SSensor {
	#[inline]
	fn set_device_ref(&self);
	#[inline]
	fn get_distance(&self, distance: &mut i32);
	#[inline]
	fn light_on(&self)-> pbio_error_t;
	#[inline]
	fn light_set(&self, bv1: &i32, bv2: &i32, bv3: &i32, bv4: &i32)-> pbio_error_t;
	#[inline]
	fn light_off(&self)-> pbio_error_t;
}
