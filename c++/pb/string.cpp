#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t,n,min,max;;
  cin>>t;
  int output1[t],output2[t];
  int x=0;
  int y=t;
  while(y!=0)
  {
    cout<<"Enter n: ";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
      cin>>a[i];
    }
    min = a[0];
    for (int i = 1; i < n; ++i)
    {
      if(a[i]<min){
        min=a[i];
      }
    }
    output1[x]=min;
    max = a[0];
    for (int i = 1; i < n; ++i)
    {
      if(a[i]>max){
        max=a[i];
      }
    }y--;
    output2[x]=max;
    x++;
  }
  for (int i = 0; i < t; ++i)
  {
    cout<<output1[i]<<" "<<output2[i]<<endl;
  }
  
  return 0;
}