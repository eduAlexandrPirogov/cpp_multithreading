#include <iostream>
#include <chrono>
#include <thread>

//function that takes a param as thread
//thread class hasn't copy constructor but has move contructor
void func(std::thread t)
{
   t.join();
};

void print()
{
   std::this_thread::sleep_for(std::chrono::milliseconds(1000));
   std::cout << "Hello, world from thread with id = " << std::this_thread::get_id() << '\n';
};

std::thread create_thread()
{
   std::thread t{print};
   return t;
};

int main()
{
   std::thread t1{print};
   func(std::move(t1));
   //t1 is no more ownership memory
   //t1.join() -- exception
   std::thread t2 = std::thread{std::move(create_thread())};
   t2.join();
};
