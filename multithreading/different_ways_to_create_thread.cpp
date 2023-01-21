#include <iostream>
#include <thread>
using namespace std;
//1 Function Pointer
/*
void fun(int x){
    while(--x)
        cout<<x<<"\n";
}
int main(){
    thread th(fun,1000);
    thread th1(fun,1005);
    th.join();
    th1.join();
    return 0;
}
*/

//2 Lambda Function
int main(){
    std::thread th1([](int x){while(--x){
        cout<<x;
    }},10);
    th1.join();
    return 0;
}