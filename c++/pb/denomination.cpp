#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int a[]={1,2,5,10,20,50,100,500,1000};
	int n,d=0,c=0;
	int output[t];
	int y=t;
	while(y!=0)
	{
		cin>>n;
		while(n!=0)
		{
			for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
			{
				if(a[i]>n)
				{
					c=a[i-1];
					break;
				}
			}
			d=d+(n/c);
			n=n%c;
		}
		output[y-1]=d;
		d=0;
		y--;
	}
	for (int i = t-1; i >=0; i--)
	{
		cout<<output[i]<<endl;
	}
	return 0;
}