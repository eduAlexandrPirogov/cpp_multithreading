#include <iostream>
#include <thread>

void print()
{
   std::cout << "Hello from thread with id = " << std::this_thread::get_id() << '\n';
};

int main()
{
   std::thread t1{print};
   std::thread t2 = std::move(t1);
   //t1 no more ownership memory
   //t1.join(); exception
   t2.join();
};
