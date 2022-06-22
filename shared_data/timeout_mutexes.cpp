#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std::literals;

std::timed_mutex m;

void task1()
{
   std::cout << "loking task1...\n";
   //Locking mutex for task1
   m.lock();

   std::this_thread::sleep_for(5000ms);
   std::cout << "Task1 unlocking mutex...\n";
   //Unlocking
   m.unlock();
};

void task2()
{
   std::this_thread::sleep_for(1000ms);
   std::cout << "trying to lock mutex from task 2..\n";

   //While we can;t lock the mutex...
   while(!m.try_lock_for(500ms))
   {
      std::cout << "I can't mate...mutex is locked already\n";
      
   }; 

   m.unlock();
   std::cout << "Task2 finally did it...\n";
   std::this_thread::sleep_for(1000ms);
};

void task3()
{
    std::this_thread::sleep_for(1000ms);
    std::cout << "trying to lock mutex from task3...\n";

    auto deadline = std::chrono::system_clock::now() + 1000ms;
    while(!m.try_lock_until(deadline))
    {
        std::cout << "Can't lock mutex from task3...\n";
	std::this_thread::sleep_for(1000ms);
    };

    std::cout << "I took a mutex from task3!\n";
    m.unlock();
};

int main()
{
   std::thread t1{task1};
   std::thread t2{task2};
   std::thread t3{task3};

   t1.join();
   t2.join();
   t3.join();
   return 0;
};
