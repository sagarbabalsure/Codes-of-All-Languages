#include<iostream>
using namespace std;
int main()
{
	int n,h[n],g[n],i,count=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>h[i]>>g[i];
	}
	for(i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
				if(h[i]==g[j]){ count++;}
			}
		}
	}
	cout<<count;
	return 0;
}