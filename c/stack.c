#include<stdio.h>
#define CAPACITY 5
void push(int);
void peek();
int pop();
int isFull(void);
int isempty(void);
void travers();
int stack[CAPACITY],top=-1;
void main()
{
	system("COLOR 76");
	
	push(5);
	push(10);
	push(7);
	peek();
	pop();
	travers();
}
void push(int element)
{
	if(isFull())
	{
      printf("stack is overflow\n");
	}
	else
	{
      top=top+1;
      stack[top]=element;
      printf("%d is pushed\n",element );
	}

}
int isFull()
{
	if(top==CAPACITY-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void peek()
{
	if(isempty())
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("peek element :%d\n",stack[top] );
	}
}
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int pop()
{
	if(isempty())
		printf("stack is empty\n");
	else
		printf("popped element is :%d\n",stack[top--] );
}
void travers()
{
	if(isempty())
	{
		printf("Stack is empty\n");
	}
	else
		{
			int i;
			printf("stack elements are: \n");
	        for(int i=0;i<4;i++)
	    	printf("%d\n",stack[i] );
	    }
}