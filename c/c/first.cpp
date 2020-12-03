#include<iostream>
using namespace std;
int main()
{
	int a[10],n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	    sum=sum+a[i];
    }
    cout<<sum<<endl;
    int ave;
    ave=sum/n;
    cout<<ave<<endl;

	return 0;
}