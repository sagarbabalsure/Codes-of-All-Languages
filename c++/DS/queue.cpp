#include<iostream>
using namespace std;
#define MAX 100
int queue[MAX],rear=-1,front=-1;
void enqueue(int x)
{
	if(rear==MAX-1)
	{
		cout<<"queue is full"<<endl;
	}
	else if(rear==-1 && front==-1)
	{
		front++;
		queue[++rear]=x;
		cout<<x<<" is pushed into queue"<<endl;
	}
	else
	{
		queue[++rear]=x;
		cout<<x<<" is pushed into queue"<<endl;
	}
}
void dequeue()
{
	if(rear==-1 && front==-1)
	{ 
		cout<<"queue is empty"<<endl;
	}
	else if(front==rear)
	{
		front--,rear--;
	}
	else
	{
		front++;
	}
}
void traverse()
{
	int head=front;
	if(front==-1 && rear==-1)
	{
		cout<<"queue is empty"<<endl;
	}
	else
	{
		for (int i = front; i<=rear; ++i)
		{
			cout<<queue[i]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	enqueue(4);
	enqueue(7);
	enqueue(6);
	enqueue(27);
	dequeue();
	traverse();
	enqueue(20);
	traverse();
	return 0;
}