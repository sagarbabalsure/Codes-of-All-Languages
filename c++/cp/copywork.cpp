#include<iostream>
using namespace std;
int main()
{
	int a[5],b[5];
	int i=0;
	for(i=0;i<5;i++){
		cin>>a[i];
	}
	for(i=0;i<=4;i++)
	{
		if(i<4){
			b[i]=a[i]-2;
		}
		else{
			b[i]=a[i]+8;
		}
	}
	for(i=0;i<5;i++){
		cout<<b[i]<<',';
	}
	return 0;
}
