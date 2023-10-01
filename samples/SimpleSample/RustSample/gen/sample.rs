mod s_sample;
mod s_sample2;
mod sample;
mod print_a;
mod client_print;
mod client_print;
mod calcu;
mod client_calculate;
use crate::{s_sample::*, print_des::*, s_sample2::*, sample::*, print_a::*, client_print::*, calcu::*, client_calculate::*};

pub struct Sample<'a, T, U>
where
	T: SSample,
	U: SSample2,
{
	pub c_print: &'a T,
	pub c_print2: &'a U,
	pub variable: &'a mut SampleVar,
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

