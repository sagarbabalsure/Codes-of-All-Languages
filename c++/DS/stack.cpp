#include<iostream>
using namespace std;
#define MAX 10
int stack1[MAX],top=-1;
void push(int x)
{
	if(top==MAX-1)
	{
		cout<<"stack is full"<<endl;
	}
	else
	{
		stack1[++top]=x;
		cout<<x<<" is pushed into stack"<<endl;
	}
}
void pop()
{
	if(top==-1)
	{
		cout<<"stack is empty"<<endl;
	}
	else
	{
		int popped_item = stack1[top];
		top--;
		cout<<popped_item<<" is popped"<<endl;
	}
}
void traverse()
{
	int head=top;
	if(top==-1)
	{
		cout<<"stack is empty"<<endl;
	}
	else
	{
		cout<<"stack elememts are: ";
		while(head!=-1)
		{
			cout<<stack1[head]<<" ";
			head--;
		}cout<<endl;
	}
}
int main()
{
	push(5);
	push(7);
	push(9);
	push(1);
	push(20);
	traverse();
	pop();
	traverse();
	push(23);
	push(52);
	traverse();
	pop();
	traverse();
	// cout<<stack1[top];
	return 0;
}