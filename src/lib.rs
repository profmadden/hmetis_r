use std::os::raw::{c_int, c_uint, c_ulong};

extern "C" {
    pub fn hm_hello();
    pub fn hm_partition(nvtxs: c_uint, nhedges: c_uint, hewt: *const c_int,
        vtw: *const c_int, eind: *const c_int, eptr: *const c_int, part: *mut c_int,
        kway: c_int, passes: c_int, seed: c_ulong, imbalance: c_int);
}