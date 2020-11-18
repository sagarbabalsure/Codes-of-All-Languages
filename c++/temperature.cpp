#include<iostream>
using namespace std;
int main()
{
	int n,a[100],count=0;
	cin>>n;
	for(int t=0;t<n;t++)
	{
		cin>>a[t];
		if(a[t]<0)
		{
			count++;
		}
		
	}
	cout<<count<<endl;
	return 0;

}