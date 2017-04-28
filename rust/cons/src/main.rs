enum List {
    Cons(i32, Box<List>),
    Nil,
}

use List::{Cons,Nil};

fn main() {
    let list =
        Cons(1, Box::new(
                Cons(2, Box::new(
                        Cons(3, Box::new(Nil))))));
    let mut l = list;
    print!("(");
    loop {
        match l {
            Cons(car, cdr) => {
                print!("{}", car);
                l = *cdr;
                match l {
                    Cons(_, _) => print!(", "),
                    Nil => (),
                }
            },
            Nil => break,
        }
    }
    println!(")");
}
