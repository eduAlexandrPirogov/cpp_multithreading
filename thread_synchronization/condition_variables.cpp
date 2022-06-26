#include <iostream>
#include <condition_variable>
#include <mutex>
#include <vector>
#include <thread>
#include <chrono>

std::vector<int> vec;
std::condition_variable read;
std::condition_variable write;
std::mutex m;

bool isOver = false;


void filling()
{
   std::cout << "Writing data...\n";
   std::unique_lock<std::mutex> lg(m);
   for(int i = 0; i < 20; i++)
   {
      vec.push_back(i);
      if(i%5 == 0 || i == 19)
      {
	 read.notify_one();
         write.wait(lg);
         std::cout << "Filling again..\n";
      }
   };
   isOver = true;
   read.notify_one();
   std::cout << "Filling is over!\n";
};

void reading()
{
   while(!isOver) {
      std::unique_lock<std::mutex> guard(m);
      read.wait(guard); 
      std::cout << "starting to read...\n";
      for(int i = 0; i < vec.size(); i++)
      {
         std::cout << vec[i] << ' ';
      };
      std::cout << '\n' << "We readed all values. Clearing vec...\n";
      vec.clear();
      std::this_thread::sleep_for(std::chrono::milliseconds(2000));
      write.notify_one();
   }
   std::cout << "Reading is over!\n";
};

int main()
{
   std::thread filler{filling};
   std::thread reader{reading};
   filler.join();
   reader.join();
};
