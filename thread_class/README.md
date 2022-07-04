# Thread class. Notes

1. Every thread has unique id. Method `std::this_thread::get_id()`
2. Thread hasn't copy constructor. Only move conctructor
3. Thread can sleep with method `std::this_thread::sleep_for(milliseconds)`
4. Thread can be detached on joined. If thread join, main thread will wait until joined thread finish it works. With detached thread parent thread will continue doing his job.
5. Every child thread has own exception stack.

