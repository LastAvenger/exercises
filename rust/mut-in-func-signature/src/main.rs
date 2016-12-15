/**
 * by cbmixx
 */

use std::env;

#[allow(unused_mut)]
fn a(mut v: Vec<i32>) {
    let p0 = &v as *const _;
    let p1 = &v[0] as *const _;
    println!("a: &v = {:?},  &v[0] = {:?}", p0, p1);
}

fn b(v: &mut Vec<i32>) {
    let p0 = v as *const _;
    let p1 = &v[0] as *const _;
    println!("b: v = {:?}, &v[0] = {:?}", p0, p1);
}

fn main() {
    let mut v = vec![1];
    let p0 = &v as *const _;
    let p1 = &v[0] as *const _;
    println!("main: &v = {:?}, &v[0] = {:?}", p0, p1);
    let func = env::args().last().unwrap();
    if func == "a" {
        a(v);
    } else {
        let r = &mut v;
        b(r);
    }
}
