#include<iostream>
using namespace std;
template<typename t1,typename t2>
void Swap(t1 &x,t2 &y)
{
 t1 temp;
 temp=x;
 x=y;
 y=temp;
}
int main()
{
	int i1=12,i2=34;
	float f1=12.54,f2=45.34;
	cout<<"before swapping"<<endl;
	cout<<"i1 and f1 are: "<<i1<<" "<<f1<<endl;
	cout<<"i2 and f2 are: "<<i2<<" "<< f2<<endl;
	Swap(i1,f1);
	Swap(i2,f2);
	cout<<"after swapping"<<endl;
	cout<<"i1 and f1 are: "<<i1<<" "<<f1<<endl;
	cout<<"i2 and f2 are: "<<i2<<" "<< f2<<endl;
	return 0;
}
