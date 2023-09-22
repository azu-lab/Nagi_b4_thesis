mod s_allocator;
mod s_sample;
mod allocator;
mod allocator2;
mod client_allocator;
mod sample;
mod print_a;
mod client_print;
use crate::{allocator::*, allocator2::*, client_allocator::*, sample::*, print_a::*, client_print::*};

fn main() {
                                
	let mut client_print_a = ClientPrint::new_printa_set_cprint1(&PRINTA);

}
