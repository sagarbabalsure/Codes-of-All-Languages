#include<iostream>
using namespace std;
int main()
{
	string s;
	int x,y,sum=0;
	cin>>s;
	int temp=int('a');
	for(int i=0;s[i]!='\0';i++)
	{
		y=int(s[i]);
		x=abs(y-temp);
		if(x>13)
		{
			sum=sum+(26-x);
		}
		else
		{
			sum=sum+x;
		}
		temp=y;
	}
	cout<<sum;
	return 0;
}