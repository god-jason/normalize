#include <iostream>

#include "pico.hpp"

void test(void* _)
{
    std::cout << "Hello World!\n";
}

int main()
{
    Pointer<string> ptr(new string("Hello, World!"));

    std::cout << *ptr.get() << std::endl;

    var a = MakePointer<string>("string");

    std::cout << *a.get() << std::endl;


    var b = Now();

    std::cout << b << " " << FormatTime(b, LOCALE_TIME) << std::endl;


    SharedMutex mutex;

    for (var i = 0; i < 10; i++)
    {
        Thread t([&mutex, i]()
        {
            //_sleep(1000);
            RDLock m(mutex);
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << i << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(10));
        });
        t.detach();
    }

    std::this_thread::sleep_for(std::chrono::seconds(30));



    return 0;
}
