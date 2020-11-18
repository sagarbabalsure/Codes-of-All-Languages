#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<int>q;
	int front=0,rare=0;
	int t,k,n;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin>>x;
			q.push(x);
		}
		Sort();
	}
}