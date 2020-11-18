#include<iostream>
using namespace std;
int main()
{
	int y,w,A=0,B=6;
	float p;
	cin>>y>>w;
	if(y>w)
	{
		A=B-(y-1);
	}
	else{
		A=B-(w-1);
	}
	p=A/B;
	cout<<p;
	return 0;
}