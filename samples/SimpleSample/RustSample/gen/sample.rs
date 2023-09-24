mod s_sample;
mod s_sample2;
mod sample;
mod print_a;
mod client_print;
mod client_print;
use crate::{s_sample::*, print_des::*, s_sample2::*, sample::*, print_a::*, client_print::*};

pub struct Sample<'a, T, U>
where
	T: SSample,
	U: SSample2,
{
	put c_print: &'a T,
	put c_print2: &'a U,
	variable: &'a mut SampleVar,
}

pub struct SampleVar {
}

pub static SAMPLE: Sample<EPrint, EPrint2> = Sample {
	c_print: &EPRINT,
	c_print2: &EPRINT2,
	variable: &SAMPLEVAR,
};

pub static SAMPLEVAR: SampleVar = SampleVar {
};

