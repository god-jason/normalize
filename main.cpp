#include <iostream>

#include "cute.hpp"

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

    std::cout << *a << std::endl;


    var b = Now();

    std::cout << b << " " << FormatTime(b, LOCALE_TIME) << std::endl;


    SharedMutex mutex;

    for (var i = 0; i < 10; i++)
    {
        Thread t([&mutex, i]()
        {
            //_sleep(1000);
            RDLock m(mutex);
            Sleep(1000);
            std::cout << i;
            Sleep(1000);
        });
        t.detach();
    }


    //
    Sleep(2000);


    return 0;
}
