#include<iostream>
using namespace std;
int main()
{
	int n,stack[n],q,x,i,count=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>stack[i];
	}
	cin>>q>>x;
	string ints[q];
	for(i=0;i<q;i++)
	{
		cin>>ints[i];
		if(ints[i]=="Harry")
			count++;
		else
			count--;
	}
	cout<<count<<endl;
	return 0;
}