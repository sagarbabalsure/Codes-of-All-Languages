#include <iostream>
#include<tuple>
using namespace std;
int main ()
{
   tuple<int, int, int>tup1;   
   tuple<int, int,int>tup2;   
    
   tup1 = make_tuple(1,2,3); 
   tup2 = make_tuple(4,5,6);
    cout<<get<0>(tup1)<<" "<<get<1>(tup1)<<" "<<get<2>(tup1)<<endl;
    cout<<get<0>(tup2)<<" "<<get<1>(tup2)<<" "<<get<2>(tup2)<<endl;
    cout<<tuple_size<decltype(tup1)>::value<<endl;
    tup1.swap(tup2);
    cout<<get<0>(tup1)<<" "<<get<1>(tup1)<<" "<<get<2>(tup1)<<endl;
    cout<<get<0>(tup2)<<" "<<get<1>(tup2)<<" "<<get<2>(tup2)<<endl;
    auto tup3=tuple_cat(tup1,tup2);
    cout<<get<0>(tup3)<<" "<<get<1>(tup3)<<" "<<get<2>(tup3)<<" ";
    cout<<get<3>(tup3)<<" "<<get<4>(tup3)<<" "<<get<5>(tup3)<<endl;




   return 0;
}
