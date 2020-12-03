#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *temp;
void insertAtHead(int x)
{
   temp=(struct node*)malloc(sizeof(struct node));
   temp->data=x;
   if(head==NULL)
  {
  	temp->next=NULL;
  	head=temp;
  	return ;
  }
  temp->next=head;
  head=temp;
}
void print()
{
	temp=head;
	printf("linked list is: \n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
void insertATbot(int x)
{
	struct node *temp1=head;
   temp=(struct node*)malloc(sizeof(struct node));
   temp->data=x;
   if(head==NULL)
  {
  	temp->next=NULL;
  	head=temp;
  	return ;
  }
  while(temp1->next!=NULL)
  	temp1=temp1->next;

  temp1->next=temp;
  temp->next=NULL;


}
/*void reverse()
{
	struct node *p=head;
	if(p==NULL)
	{
		return;
	}
	reverse(p->next);
	printf("%d\n",p->data );
}*/
int main()
{
	insertAtHead(5);
	insertAtHead(12);
	insertAtHead(15);
	insertATbot(20);
	insertATbot(30);
	insertATbot(40);
	
	print();
	//reverse();
	return 0;
}