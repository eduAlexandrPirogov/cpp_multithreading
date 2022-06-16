#include <iostream>
#include <thread>
#include <chrono>

void print()
{
  std::cout << "Hello from thread with id = " << std::this_thread::get_id() << '\n';
};

int main()
{
   std::thread t1{print};
   std::thread t2{print};
   std::thread t3{print};

   t1.join();
   t2.join();
   t3.join();
};
