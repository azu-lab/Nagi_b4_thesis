use crate::{s_hello::*, t_alice::*};

pub struct TCarol<'a, T>
where
	T: SHello,
{
	pub c_person: &'a T,
}

pub struct ECarolForTCarol<'a>{
	pub cell: &'a TCarol<'a, EAliceForTAlice<'a>>,
}

pub static CAROL: TCarol<EAliceForTAlice> = TCarol {
	c_person: &EALICEFORALICE2,
};

pub static ECAROLFORCAROL: ECarolForTCarol = ECarolForTCarol {
	cell: &CAROL,
};

impl<T: SHello> TCarol<'_, T> {
	pub fn get_cell_ref(&self) -> &T {
		&self.c_person
	}
}
