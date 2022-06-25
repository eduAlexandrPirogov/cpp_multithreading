#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>

std::mutex mutex1, mutex2;

void func1()
{
   std::cout << "Locking mutex1...\n";
   std::unique_lock<std::mutex> lk1(mutex1); 
   std::this_thread::sleep_for(std::chrono::milliseconds(500));
   std::cout << "trying to lock mutex2..\n";
   std::unique_lock<std::mutex> lk2(mutex2);
};

void func2()
{
   std::cout << "Locking mutex2...\n";
   std::unique_lock<std::mutex> lk1(mutex2);
   std::this_thread::sleep_for(std::chrono::milliseconds(500));
   std::cout << "trying to lock mutex1...\n";
   std::unique_lock<std::mutex> lk2(mutex1);
};

int main()
{
   std::thread t1{func1};
   std::thread t2{func2};
   t1.join();
   t2.join();
   return 0;
};
