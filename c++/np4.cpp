#include<iostream>
using namespace std;
int add(int a,int b){
    return a+b;
}

double add(double a, double b){
	return a+b;
}
int main()
{
	int a=10,b=20;
	int c=add(a,b);
	double d=add(a,20.2);
	cout<<c<<" "<<d;
	return 0;
}