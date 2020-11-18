#include<iostream>
using namespace std;
template <typename T>
void Swap(T &x,T &y)
{
  T temp;
  temp=x;
  x=y;
  y=temp;
}
int main()
{
  int i1,i2;
  cin>>i1>>i2;
  float f1,f2;
  cin>>f1>>f2;
  cout<<"before swapping"<<endl;
  cout<<i1<<" and "<< i2<<endl;
  cout<<f1<<" and "<<f2<<endl;

  Swap(i1,i2);
  Swap(f1,f2);
  cout<<"before swapping"<<endl;
  cout<<i1<<" and "<< i2<<endl;
  cout<<f1<<" and "<<f2<<endl;

  return 0;
}