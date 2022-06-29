#include <iostream>
#include <vector>
#include <thread>

int count = 0;

void task()
{
   for(int i = 0 ;i < 10000000; i++)
	   ++count;
};

int main()
{
   std::vector<std::thread> vec;
   for(int i = 0; i < 10; i++)
	   vec.push_back(std::thread{task});
   for(auto& t : vec)
	   t.join();
   std::cout << count << '\n';
};
