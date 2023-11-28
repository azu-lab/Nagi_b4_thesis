use crate::kernel_cfg::*;
static TASK1_REF:TaskRef = unsafe{TaskRef::from_raw_nonnull(NonZeroI32::new(TASK1).unwrap())};
