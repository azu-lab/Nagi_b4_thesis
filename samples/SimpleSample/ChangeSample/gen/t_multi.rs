use crate::{s_multi::*};

pub struct TMulti
{
}

pub struct EMultiForTMulti<'a>{
	pub cell: &'a TMulti,
}

pub static MULTI1: TMulti = TMulti {
};

pub static EMULTIFORMULTI1: EMultiForTMulti = EMultiForTMulti {
	cell: &MULTI1,
};

pub static MULTI2: TMulti = TMulti {
};

pub static EMULTIFORMULTI2: EMultiForTMulti = EMultiForTMulti {
	cell: &MULTI2,
};

