#include<iostream>
#include<cmath>
using namespace std;

int main()
{
   int n,R,count=0,Total=0,temp;
   cin>>n;
   temp=n;
   while(temp!=0)
   {
   	temp=temp/10;
   	count++;
   }
   temp=n;
   while(temp!=0)
   {
   	R=temp%10;
   	Total+=pow(R,count);
   	temp=temp/10;
   }
   cout<<Total<<endl;
   return 0;
}
