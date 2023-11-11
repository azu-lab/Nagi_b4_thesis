#![no_std]
#![feature(const_option)]

use core::num::NonZeroI32;
use itron::*;
use crate::print_a::EPRINTFORPRINTA as c_task_body;

pub const TASK1_ID: NonNullID = NonZeroI32::new(1).unwrap();
pub const TASK: TaskRef = unsafe { TaskRef::from_raw_nonnull(TASK1_ID) };

#[no_mangle]
pub extern "C" fn tTask_start(_: usize) {
/*tTask型の呼び口につながっているセルの関数を呼び出す*/

	c_task_body.main();

}
