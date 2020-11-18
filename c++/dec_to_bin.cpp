#include<iostream>
using namespace std;
int i;
int main()
{
	int n,a[16],x=0;
	cin>>n;
	while(n!=0)
	{
		a[x]=n%2;
		n=n/2;
		x++;
	}
	for (int i = x-1; i >=0; i--)
	{
		cout<<a[i];
	}cout<<endl;
	return 0;
}