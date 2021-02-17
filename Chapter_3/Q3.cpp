#include <iostream>

void d() {  // here
}

void c() {
}

void b() {
    c();
    d();
}

void a() {
    b();
}

int main() {
    a();
    // stack: bottom -> top
    //        main, a, b, d
    return 0;
}