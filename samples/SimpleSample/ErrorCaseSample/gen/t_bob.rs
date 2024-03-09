use crate::{s_hello::*, t_alice::*};

pub struct TBob<'a, T>
where
	T: SHello,
{
	pub c_person: &'a T,
}

pub struct EBobForTBob<'a>{
	pub cell: &'a TBob<'a, EAliceForTAlice<'a>>,
}

pub static BOB: TBob<EAliceForTAlice> = TBob {
	c_person: &EALICEFORALICE1,
};

pub static EBOBFORBOB: EBobForTBob = EBobForTBob {
	cell: &BOB,
};

impl<T: SHello> TBob<'_, T> {
	pub fn get_cell_ref(&self) -> &T {
		&self.c_person
	}
}
