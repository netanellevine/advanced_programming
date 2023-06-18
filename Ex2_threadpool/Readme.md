# Advanced programming 2
We decided to use C++11 in this assignment. 
 
Our code is found in main.cpp queue.cpp task.cpp thread_pool.cpp.  
I will explain shortly about what code is found in each file. Further explaination can be found in those files.  

myTask is an example for runnable of our threads, it is a task for each thread to perform.
queue is a blocking queue needed to manage our threads, this has the option to notify all listeners of a pushing into the queue.  
thread_pool contains the code for our threadpool, contain management of each task and thread, to perform the encryption and decryption required.  

Our cmdTool expect to receive his input from stdIn.  

In order to run our program perform the following steps.
1. ```make```   
Running option A
2. ```./coder <key> <option>```
Write whatever you want and when finished press CTRL + D.  

Running option B 
input from stream example.  
2. ```echo "testing" | ./coder <key> <option>```

Output can be redirecting to a file.  

