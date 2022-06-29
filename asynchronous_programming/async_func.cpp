#include <future>
#include <iostream>
#include <chrono>
#include <thread>
void task()
{
   std::this_thread::sleep_for(std::chrono::milliseconds(2000));
   std::cout << "Hello, world!\n";
};

int main()
{
   std::async(task);
};
