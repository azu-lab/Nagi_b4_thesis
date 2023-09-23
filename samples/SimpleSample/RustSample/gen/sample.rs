mod s_sample;
mod sample;
mod print_a;
mod client_print;
use crate::{s_sample::*, print_des::*, sample::*, print_a::*, client_print::*};

pub struct Sample<'a, T>
where
	T: SSample,
{
	pub c_print1: &'a T,
	variable: &'a mut SampleVar,
}

pub struct SampleVar {
}

pub static SAMPLE: Sample<EPrint> = Sample {
	c_print1: &EPRINT,
	variable: &SAMPLEVAR,
};

pub static SAMPLEVAR: SampleVar = SampleVar {
};

	let mut client_print_a = ClientPrint::new_printa_set_cprint1(&PRINTA);

}
