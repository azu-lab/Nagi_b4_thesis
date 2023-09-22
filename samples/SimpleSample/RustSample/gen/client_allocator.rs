use crate::s_allocator::*;

pub struct ClientAllocator<'a, T> {
    pub call : Option<&'a, T>,
}

impl<'a, T: SAllocator<<ClientAllocator<'a, T>>> ClientAllocator<'a, T> {

    pub fn new_allocator_set_cprint1_print_varsend(component: &'a T) -> ClientAllocator<'a, T> {
        ClientAllocator {
            call: Some(component),
		}
	}

    pub fn new_allocator2_set_cprint1_print_varsend(component: &'a T) -> ClientAllocator<'a, T> {
        ClientAllocator {
            call: Some(component),
		}
	}

	pub fn alloc(&mut self, size: &i32, buf: &mut unknown) {
		self.call.unwrap().alloc(self, size, buf);
	}

	pub fn dealloc(&mut self, buf: &unknown) {
		self.call.unwrap().dealloc(self, buf);
	}

}
