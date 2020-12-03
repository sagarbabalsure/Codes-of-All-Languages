#include<stdio.h>
#define max 10
int stack[max],top=-1,str1,str2,str3;
void push(str1[])
{
	if(top=max-1)
	{
		printf("stack is full\n");
	}
	else
	{
		printf("stack elements are: %s",stack[++top] );
		str2[]=stack[++top];

	}
}
void pop()
{
	if(top==-1)
		printf("stack is empty\n");
	else
	{
		printf("popped data is %d\n",stack[top--] );
		str3[]=stack[top--];
	}
}
int main()
{
 printf("ENter string\n");
 for (int i = 0; i < max; ++i)
 {
 	scanf("%s",str1[i]);
 	push(str1[i]);
 	pop();
 }
 
 return 0;
}