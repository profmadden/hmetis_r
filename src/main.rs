
// Building on Rocinante:
// cargo build --target x86_64-apple-darwin

fn main() {
    println!("hmetis wrapper");

    unsafe {
        hmetis_r::hello();
        // hmetis_r::partition(nvtxs, nhedges, hewt, vtw, eind, eptr, part, kway, passes, seed);
    }
}
