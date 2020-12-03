#include<stdio.h>
#include<stdlib.h>
#define max 5
void push(int x);
int pop();
void peek();
void traverse();
int stack[max],top=-1;
int main()
{
	int x,ch;
	while(1)
   {
	printf("Enter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("Enter element you want to push: ");
	           scanf("%d",&x);
	           push(x);
		       break;
		case 2:pop();
		      break;
		case 3:peek();
		      break;
		case 4:
		      traverse();
		      break;
		case 5:exit(0);
		default:
		      printf("error\n");
	}
}

}
void push(int x)
{
	if(top==max-1)
		printf("stack is full\n");
	else
	{
		stack[++top]=x;
		printf("pushed element is %d\n",x );
	}
}
int pop()
{
	if(top==-1)
		printf("stack is empty\n");
	else
	{
     printf("popped element is %d\n",stack[top--] );
	}
}
void peek()
{
	if(top==-1)
		printf("stack is empty\n");
	else
	{
		printf("top element is %d\n",stack[top] );
	}
}
void traverse()
{
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
		{
			int i;
			printf("stack elements are: \n");
	        for(int i=0;i<max;i++)
	    	printf("%d\n",stack[i] );
	    }
}