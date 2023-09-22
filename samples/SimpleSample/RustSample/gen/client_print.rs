use crate::s_sample::*;

pub struct ClientPrint<'a, T> {
    pub call : Option<&'a, T>,
	pub variable: i16,
}

impl<'a, T: SSample<<ClientPrint<'a, T>>> ClientPrint<'a, T> {

    pub fn new_printa_set_cprint1(component: &'a T) -> ClientPrint<'a, T> {
        ClientPrint {
            call: Some(component),
			variable: 0,
		}
	}

	pub fn print(&mut self, varin: &i8, varsend: mut unknown, varout: &mut unknown, varout2: &mut unknown) {
		self.call.unwrap().print(self, varin, varsend, varout, varout2);
	}

}
