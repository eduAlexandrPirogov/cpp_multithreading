# Asynchronous Programming

There is another tool for creating thread -- `std::asynkc(func)`. 
From async you can also get a result with method `get()`.

## Types of asyncs

1. Deferred -- type of async when thread starts when reach method `get()`. Has id equals of it parent-thread id.
2. Async -- type of async when thread starts work immedieatly. Has id differ from it parent-thread id.

