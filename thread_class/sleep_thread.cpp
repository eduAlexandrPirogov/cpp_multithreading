#include <iostream>
#include <chrono>
#include <thread>

void hello(int seconds)
{
   //sleeps thread for millisecond * 1000
   std::this_thread::sleep_for(std::chrono::milliseconds(seconds*1000));
   std::cout << "Hello world!\n";
};

int main()
{
   //passing an argument after comma 
   std::thread t1{hello, 1};
   std::thread t2{hello, 2};
   std::thread t3{hello, 3};
   t1.join();
   t2.join();
   t3.join();
   return 0;
};
