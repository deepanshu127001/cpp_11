#include <iostream>
#include <chrono>
#include <iostream>
#include <thread>

// using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;
ull os = 0;
ull es = 0;
void EvenSum(ull start,ull end){
    for(ull i=0;i<=end;i++){
        if((i&1)==0){
            es+=i;
        }
    }
}
void OddSum(ull start ,ull end){
    for(ull i = 0;i<=end;i++){
        if((i&1)==1){
            os+=i;
        }
    }
}
int main(){
    ull start  = 0 , end = 1900000000;
    auto START = high_resolution_clock::now();
    std::thread t1(EvenSum,start,end);
    std::thread t2(OddSum,start,end);
    t1.join();
    t2.join();
    // EvenSum(start,end);
    // OddSum(start,end);
    auto STOP = high_resolution_clock::now();
std::cout<<"even sum"<<es<<std::endl;
std::cout<<"odd sum"<<os;
auto duration = duration_cast<microseconds>(STOP - START);
 std::cout << "\nTime taken by function: "
         << duration.count()/1000000 << "seconds" << std::endl;  
         return 0;
}