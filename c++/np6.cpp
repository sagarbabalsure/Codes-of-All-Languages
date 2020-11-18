#include<iostream>
using namespace std;

int add(int x,int y){
	return x+y;
}
double add(double x,double z){
	return x+z;
}
int main()
{
	int a=5;
	int c=add(a,6);
	double d=add(a,6.6);
	cout<<c<<" "<<d;
	return 0;
}