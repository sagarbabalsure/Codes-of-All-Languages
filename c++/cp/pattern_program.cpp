#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int c = -1;
	for (int i = 65; i < n+65; ++i)
	{
		c++;
		for (int j = i; j<=i+c; ++j)
		{
			cout<<char(j);
		}cout<<endl;
	}
}