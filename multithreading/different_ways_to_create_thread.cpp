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
/*
int main(){
    //we can directly inject lambda at thread creation time 
    std::thread th1([](int x){while(--x){
        cout<<x;
    }},10);
    th1.join();
    return 0;
}
*/

//3 functors 
/*
class Base{
    public :
    void operator()(int x){
        while(--x){
            cout<<x;
        }
    }
};
int main(){
    std::thread th(Base(),10);
    th.join();
    return 0;
}
*/

//4 Non static member function 
/*
class Base{
    public :
        void run(int x){
            while(--x)
                cout<<x;
        }
};
int main(){
    Base b;
    std::thread th(&Base::run,&b,10);
    th.join();
    return 0;
}
*/

//5 static member function 
class Base{
    public :
        static void run(int x){
            while(--x){
                cout<<x;
            }
        }
};
int main(){
    std::thread th(&Base::run,10);
    th.join();
    return 0;
}