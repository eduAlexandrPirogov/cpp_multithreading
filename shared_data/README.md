# Working with shared data. Notes

A race condition is when two or more threads are working on the same variable (same piece of memory).

Such sections of code are called `critical section`. 

Mutexes are tool that's help to deal with such `critical sections`. The mutex can lock a section of code, and another thread cannot execute the critical section until the mutex is unlocked.

A mutex can:
– lock() – lock a section of code
- try_block() - try to block section of code.
– unlock() – unlock a piece of code

## Keep in mind!

1. If an exception is thrown (or a situation occurs when the mutex is not unlocked), then the mutex will be forever in the lock. std::lock_guard is a wrapper class that, in case of an exception, uses a mutex.
2. If we lock section of code we must also unlock it. Otherwise our programm will stuck.

There are many types of mutexes and locks so better use `std::lock_guard`. It unlocks critical section without "programmers hands".

## Deadlocks and Livelocks

Mutexes can lead to the next problems: deadlock and livelock.

**Deadlock** -- when two too stubborn waiters meet in the doorway.
**Livelock** -- when two overly polite waiters meet in the doorway.

# When to use mutexes and when to avoid

1. don’t lock mutex for any longer than necessary
2. don’t lock any more data than necessary
3. don’t make locking too fine-grained


1. make the shared data a member of class
2. make the mutex a member of a class
3. make the task function a member function
4. provide a getter function to retrieve shared data
5. when using a mutex to protect shared data, use classes instead of global data and function

