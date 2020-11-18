#include<iostream>
using namespace std;
int main()
{
	int n,b,d,count=0;
	cin>>n>>b>>d;
	int a[n],i=0,sum=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		if(a[i] <= b)
		{
			sum=sum+a[i];
			if(sum > d)
			{
				count++;
				sum=d;
			}
		}
	}
	cout<<count;
	return 0;
}