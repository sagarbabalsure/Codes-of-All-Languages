#include<iostream>
using namespace std;
int main()
{
	int a[5],i,n,p,x;
	cout<<"Enter no of elements in array: "<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"ENter position and element in array :";
	cin>>p>>x;
	for(i=n;i>=p;i--)
	{
		a[i]=a[i-1];
	}
	a[p]=x;
	for(i=0;i<n+1;i++)
	{
		cout<<a[i]<<"\t";
	}
    return 0;
}