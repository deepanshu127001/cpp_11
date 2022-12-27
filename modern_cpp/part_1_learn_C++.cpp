//introduction
//Initializer list
#include <iostream>
#include <initializer_list>
#include <vector>
class vBool{
    std::vector<int> m_vector;
    public:
    vBool(const std::initializer_list<int> &v){
        for(std::initializer_list<int>::iterator itr;itr!=v.end();itr++){
            m_vector.push_back(*itr);
        }
    }
};
int main(){
  /*
  int arr[]={5,4,3,2,1};
  for(int val : arr){
    std::cout<<val<<" ";
  }
  //initializer_list was introduced in c++ 11 before this we can only insert values using push_back() method
 std::vector <int> v={1,2,3,4};//calling initializer list consructor
  for(int val : v){
    std::cout<<val<<" ";
  }
  */
 vBool v{1,2,3,4};
}
