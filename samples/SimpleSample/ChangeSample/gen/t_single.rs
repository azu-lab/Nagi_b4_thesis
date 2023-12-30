use crate::{s_multi::*, t_multi::*};

pub struct TSingle<'a, T, U>
where
	T: SMulti,
	U: SMulti,
{
	pub c_multi1: &'a T,
	pub c_multi2: &'a U,
}

pub static SINGLE: TSingle<EMultiForMulti1, EMultiForMulti2> = TSingle {
	c_multi1: &EMULTIFORMULTI1,
	c_multi2: &EMULTIFORMULTI2,
};

