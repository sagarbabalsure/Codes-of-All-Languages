#include<iostream>
using namespace std;
int main()
{
	int T,d;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		long long a,b;
		cin>>a>>b;
		d=abs(a-b);
		cout<<d<<endl;
	}
	return 0;
}