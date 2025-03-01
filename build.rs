fn main() {
    cc::Build::new()
        .file("src/wrap.c")
        .compile("hmetis_r");
    println!("cargo::rustc-link-search=/usr/local/lib");
    println!("cargo::rustc-link-lib=hmetis");
    println!("cargo:rerun-if-changed=src/wrap.c");
}
