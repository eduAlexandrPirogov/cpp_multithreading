#include <future>
#include <iostream>
#include <chrono>
#include <thread>

int task()
{
   std::cout << std::this_thread::get_id() << " thread id\n";
   std::this_thread::sleep_for(std::chrono::milliseconds(2000));
   std::cout << "Hello, world!\n";
   return 50;
};

int main()
{
   std::cout << std::this_thread::get_id() << " main thread id\n";
   auto result = std::async(std::launch::async, task);
   std::cout << "Getting result...\n";
   std::cout << result.get() << '\n';;
};
