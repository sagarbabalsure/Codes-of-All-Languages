#include<stdio.h>
#define max 5
void enqueue(int);
void dequeue();
void traverse();
int q[max],front=-1,rear=-1;
int main()
{
	int x;
	enqueue(5);
	enqueue(7);
	enqueue(2);
	dequeue();
	traverse();
	return 0;
}
void enqueue(int x)
{
	if(rear==max-1)
		printf("queue is full\n" );
	else
	{
		q[++rear]=x;
		printf("queued element is %d\n",x );
		front++;
	}
}
void dequeue()
{
	if(front==rear==-1)
		printf("queue is empty\n");
	else
	{
		printf("dequeued element is %d\n",q[front]);
		front++;
	}
}
void traverse()
{
	if(rear==-1)
		printf("queue is empyt\n");
	else
	{
		int i;
		for(i=0;i<max;i++)
		{
			printf("queue elements are %d\n",q[i] );
		}
	}
}