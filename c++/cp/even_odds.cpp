#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	int arr1[n],arr2[n],s[n];
	int x=0,y=0;
	for(int i=1;i<=n;i++)
	{
		
		if(i%2==0)
		{
			arr1[x]=i;
			x++;
		}
		else{
			arr2[y]=i;
			y++;
		}
	}
	for(int i=0;i<y;i++)
	{
		s[i]=arr2[i];
	}
	for(int i=0,m=y;i<x,m<n;i++,m++)
	{
		s[m]=arr1[i];
	}
	cout<<s[k-1];
	return 0;
}