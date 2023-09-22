pub trait SAllocator<T> {

	fn alloc(&self, var: &mut T , size: &i32, buf: &mut unknown);

	fn dealloc(&self, var: &mut T , buf: &unknown);

}
