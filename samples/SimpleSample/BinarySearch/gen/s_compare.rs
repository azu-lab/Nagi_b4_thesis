pub trait SCompare {
	#[inline]
	fn cmp(&self, value: &i32, key: &i32, left: &mut i32, right: &mut i32, mind: &i32);
}
