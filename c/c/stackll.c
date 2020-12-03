#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *temp;
void push(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	if(head==NULL)
	{
		head=temp;
		temp->next=NULL;
		return;
	}
	temp->next=head;
	head=temp;
}
void pop()
{
	if (head == NULL)
	{
		printf("Empty!\n");
		return;
	}
	printf("data: %d\n", head->data);
	struct node* temp = head;
	head = head->next;
	free(temp);
}
void top()
{
	if(head==NULL)
		printf("stack is empty\n");
	else
	{
		printf("%d\n",head->data );
	}
}
int main()
{
	int x,ch;
	while(1)
	{
	printf("Ener choice: \n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("Enter element: \n");
		       scanf("%d",&x);
		       push(x);
		       break;
		case 2:pop();
		       break;
		case 3:top();
		       break;
		case 4:exit(0);
		default:
		     printf("error\n");
	}
}
	return 0;
}