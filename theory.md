Exercise 1 - Theory questions
-----------------------------
 
 ### What is the difference between concurrency and parallelism?
 > concurrency is how able a program is to perform some of it's code OoR while still being correct. Parallelism is when a problem is divided into smaller problems and can be solved at the same time across different workers while still producing the correct result.
 
 ### Why have machines become increasingly multicore in the past decade?
 > To make a program in general faster one can implement faster ISA, increase the frequency, reduce the memory latency, increase the number of processing units and just write better software / compilers. Last decade computers increased they frequency but now it's getting at a point where increasing frequency is harder and makes computation out of spec. Therefore manufactures are increasing the amount of cores so the work can be done faster by simply having more workers.
 
 ### Why do we divide software (programs) into concurrently executing parts (like threads or processes)?
 (Or phrased differently: What problems do concurrency help in solving?)
 > There are several reasons. First of all you can perform computation simultaneously and therefore save time. It might in some languages and in some cases increase the readability and therefore maintainability. It reduces power consumption and CPU time in cases where alternative solution would have been polling in stead of interrupt routines.
 
 ### Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
 (Come back to this after you have worked on part 4 of this exercise)
 > It depends.
 
 ### What is the conceptual difference between threads and processes?
 > A process can have many threads of execution. A process is just a program or a service. All threads within a process share the same process ID.
 
 ### Some languages support "fibers" (sometimes called "green threads") or "coroutines"? What are they?
 > fibers or green threads are simulation of threading on a host that natively does not support threading. 
 
 ### What is the Go-language's "goroutine"? A C/POSIX "pthread"?
 > goroutine and pthread is a thread.
 
 ### In Go, what does `func GOMAXPROCS(n int) int` change? 
 > GOMAXPROCS sets the maximum number of CPUs that can be executing simultaneously and returns the previous setting. If n < 1, it does not change the current setting. The number of logical CPUs on the local machine can be queried with NumCPU. This call will go away when the scheduler improves.



 
 
 
 
