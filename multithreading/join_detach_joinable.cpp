//Topic : Use of join() , detach() and joinable() in c++ 11

//Join Notes
//0 Once a thread is started we wait for this thread to finish by calling join() on thread object.
//1 Double join will result into program termination.
//2 If needed we should check thread is joinable before joining (using joinable() function)

// Detach Notes
//0 This is used to detach newly created thread from the parent thread .
//1 Always check before detaching a thread that it is joinable otherwise we may end up double detaching and double detach() will result into program termination. 
//2 If we have detached thread and main function is returning then the detached thread execution is suspended.

//NOTES
//Either join() or detach() should be called on thread object, otherwise during thread object's destructor it will terminate the program . Because insider destructor it checks if thread is still joinable? If yes then it will terminates the program
#include <iostream>
#include <chrono>
#include <thread>
void fun(int x){
    while (--x)
    {
        std::cout<<x;
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
}
int main(int argc, char const *argv[])
{
    std::thread th(fun,10);
    int x=10;
    while(--x)
    std::cout<<"\nmain()"<<x;
    if(th.joinable())
        th.join();
    //th.detach() detach the thread from parent thread 
    std::cout<<"end";
    return 0;
}
