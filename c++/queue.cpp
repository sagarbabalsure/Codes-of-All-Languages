#include<iostream>
#include<queue>
using namespace std;
void showq(queue<int>q)
{
	while(!q.empty())
	{
		cout<<q.front();
		q.pop();
	}
}
int main(int argc, char const *argv[])
{
	queue<int>q1;
	q1.push(1);
	q1.push(3);
	q1.push(5);
	q1.push(7);
	cout<<q1.size()<<endl;
	cout<<q1.front()<<endl;
	cout<<q1.back()<<endl;
	q1.pop();
	cout<<q1.size()<<endl;
	cout<<q1.front()<<endl;
	cout<<q1.back()<<endl;
	cout<<q1.empty()<<endl;
    q1.push(9);
    showq(q1);
	return 0;
}