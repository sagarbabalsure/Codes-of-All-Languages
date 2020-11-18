#include <iostream>

using namespace std;    
    
int main ()
{
   pair<int,int>pair1;
   pair<int,string>pair2;
   int a,b;
   cin>>a>>b;
   pair1=make_pair(a,b);
  
   pair2=make_pair(4,"sagar");
   cout<<pair1.second<<" "<<pair2.first<<endl;

   swap(pair1.second,pair2.first);
   cout<<pair1.second<<" "<<pair2.first<<endl;
   

   if(pair1.first>=pair2.first)
   {
    cout<<pair1.first<<" is greater"<<endl;
   }
   else
   {
    cout<<pair2.first<<" is greater"<<endl;
   }
   return 0;
}