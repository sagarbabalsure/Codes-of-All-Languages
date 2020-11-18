#include<stdio.h>
int add(int x,int y,int z){
	return x+y+z;
}
double add(double x,double y=0,double z){
	return x+y;
}
int main()
{
	cout<<add(5,6,7);
	cout<<add(5.5,6.6);
	return 0;
}