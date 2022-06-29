#include <future>
#include <iostream>
#include <chrono>
#include <thread>

int task()
{
   std::this_thread::sleep_for(std::chrono::milliseconds(2000));
   std::cout << "Hello, world!\n";
   return 50;
};

int main()
{
   auto result = std::async(task);
   std::cout << "Getting result...\n";
   std::cout << result.get() << '\n';;
};
