use std::os::raw::{c_int, c_uint, c_ulong};

extern "C" {
    pub fn hello();
    pub fn partition(nvtxs: c_uint, nhedges: c_uint, hewt: *const c_int, vtw: *const c_int, eind: *const c_ulong, eptr: *const c_uint, part: *mut c_int, kway: c_int, passes: c_int, seed: c_ulong);
}