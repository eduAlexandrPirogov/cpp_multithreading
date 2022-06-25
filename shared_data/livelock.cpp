#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>

std::timed_mutex mutex1, mutex2;

void func1()
{
   bool isReady = false;
   while(!isReady)
   {
      std::cout << "I see you are busy! I'll wait until you've done\n";
      std::lock_guard lk(mutex1);
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      isReady = mutex2.try_lock_for(std::chrono::milliseconds(5000));
   };
};

void func2()
{
   bool isReady = false;
   while(!isReady)
   {
      std::cout << "Oh, you are busy! Ok, i'll take a break\n";
      std::lock_guard lk(mutex2);
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      isReady = mutex2.try_lock_for(std::chrono::milliseconds(5000));
   };
};

int main()
{
   std::thread t1{func1};
   std::thread t2{func2};
   t1.join();
   t2.join();
   return 0;
};
