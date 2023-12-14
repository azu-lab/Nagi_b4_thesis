pub trait SSensor {

	fn set_device_ref(&self);

	fn get_distance(&self, distance: &mut i32);

	fn light_on(&self)-> pbio_error_t;

	fn light_set(&self, bv1: &i32, bv2: &i32, bv3: &i32, bv4: &i32)-> pbio_error_t;

	fn light_off(&self)-> pbio_error_t;

}
