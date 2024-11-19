#include <iostream>

#include "pico/pico.hpp"

int main() {

    Pointer<string> ptr(new string("Hello, World!"));

    std::cout << *ptr.get() << std::endl;

    var a = Make<string>("string");

    std::cout << *a.get() << std::endl;

    return 0;
}
