#include <iostream> 
#include<queue> 
using namespace std; 
int main()
{
	queue<int>q;
	int x;
	cout<<"press 0 to exit"<<endl;
	do{
		cin>>x;
		q.push(x);
	}while(x);
	cout<<q.size()<<endl;
	cout<<q.front()<<endl;
	cout<<q.back()<<endl;
	cout<<"data in queue"<<endl;
	while(!q.empty())
	{
		cout<<q.front()<<endl;
		q.pop();
	}
	
	return 0;
}