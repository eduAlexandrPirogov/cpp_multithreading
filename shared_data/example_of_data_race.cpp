#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>

using namespace std::literals;
std::vector<int> vec( 2000 );

int a = -1;

void sum(int b)
{
    a = a * b + 3;
    std::cout << "Sum a = " << a <<'\n';
}

void setA(int b)
{
    a = b;
}

void fill()
{
    for (int i = 0; i < 2000; i++)
    {
        vec[i] = i;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(20ms));
    //
}

void print(std::string& str)
{
    for (int i = 0; i < 50; i++)
    {
        std::cout << str[0] << str[1] << str[2] << str[4] << str[5] << str[6] << '\n';
    }
}

int main()
{
    std::string str{ "qweasdzxc" };
    std::thread t1{ print, std::ref(str)};
    std::thread t2{ print, std::ref(str) };
    std::thread t3{ print, std::ref(str) };

    std::thread t4{fill };
    std::thread t5{fill };
    std::thread t6{fill };


    std::thread t8{ setA, 2 };
    std::thread t9{ setA, 3 };
    std::thread t7{ setA, 1 };

    t1.join();
    t2.join();
    t3.join();  
    
    t4.join();
    t5.join();
    t6.join();

    t7.join();
    t8.join();
    t9.join();

    for (const auto& elem : vec)
        std::cout << elem << ' ';
    std::cout << '\n';
    std::cout << "a = " << a << '\n';

    std::thread tt1{ sum, 2};
    std::thread tt2{ sum, 3 };
    std::thread tt3{ sum, 1 };

    tt1.join();
    tt2.join();
    tt3.join();

    std::cout << "a = " << a << '\n';

}
