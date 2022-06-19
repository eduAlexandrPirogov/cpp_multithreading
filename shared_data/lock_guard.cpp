#include <thread>
#include <mutex>
#include <iostream>
#include <string>
#include <chrono>

void task1(const std::string& str)
{
   for(int i = 0; i < 5; i++)
   {
      std::cout << str[0] << str[1] << str[2] << '\n';
      std::this_thread::sleep_for(std::chrono::milliseconds(50));


   };
}

std::mutex m;

void try_catch(const std::string& str)
{
   try {
      m.lock();
      for(int i = 0; i < 5; i++)
      {
         std::cout << str[0] << str[1] << str[2] << '\n';
	 throw std::exception();
         std::this_thread::sleep_for(std::chrono::milliseconds(50));
      };
   }catch(...) {
     std::cout << "Error caught!\n";
    }
    m.unlock();
};

void lock_guard(const std::string& str)
{
try{
      std::lock_guard<std::mutex> guard_Mutex(m);

      for(int i = 0; i < 5; i++)
      {
         std::cout << str[0] << str[1] << str[2] << '\n';
	 throw std::exception();
         std::this_thread::sleep_for(std::chrono::milliseconds(50));
      };
} catch(...) { };
};

int main()
{
   std::string str1{"qwe"};
   std::string str2{"asd"};
   std::string str3{"zxc"};

   std::thread t1{lock_guard, str1};
   std::thread t2{lock_guard, str2};
   std::thread t3{lock_guard, str3};

   t1.join(); t2.join(); t3.join();
};
