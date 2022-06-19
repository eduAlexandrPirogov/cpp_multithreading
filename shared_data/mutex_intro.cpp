#include <thread>
#include <mutex>
#include <iostream>
#include <vector>

std::mutex my_mutex;

class myVector
{
   protected:
      std::vector<int> vec;
   public:
      myVector() = default;

      virtual void push_back(int item)
      { 
	 for(int i = 0; i < 10; i++)
 	    vec.push_back(item);
      };

      void print()
      {
	 std::cout << "Vec size = " << vec.size() << '\n';
         for(const auto& item : vec)
            std::cout << item << ' ';
	 std::cout << '\n';
      };
};


class mutexedVector : public myVector
{
   std::mutex m;
   public:
      mutexedVector() = default;

      void push_back(int item) override
      {
         m.lock();
	 for(int i = 0; i < 10; i++)
            vec.push_back(item);
         m.unlock();
      };
};

int main()
{
   myVector vec{};
   std::cout << "Filling vector...\n";
   std::thread t1{&myVector::push_back, std::ref(vec), 1};
   std::thread t2{&myVector::push_back, std::ref(vec), 2};
   std::thread t3{&myVector::push_back, std::ref(vec), 3};

   t1.join(); t2.join(); t3.join();

  
   mutexedVector m_vec{};
   
   std::cout << "Filling mutexed vector...\n";
   std::thread tm1{&mutexedVector::push_back, std::ref(m_vec), 1};
   std::thread tm2{&mutexedVector::push_back, std::ref(m_vec), 2};
   std::thread tm3{&mutexedVector::push_back, std::ref(m_vec), 3};

   tm1.join(); tm2.join(); tm3.join();
   

   vec.print();
   m_vec.print();
};
