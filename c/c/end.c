#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head = NULL;
void create(int n)
{
	struct node *temp,*newnode;
	int x,i;
	head=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("unable to locate momory\n");
	    exit(0);
    }
	printf("ENter data for head: \n");
	scanf("%d",&x);
	head->data=x;
	head->next=NULL;


	temp=head;
	for(i=2;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node)*n);
		printf("ENter data for %d: \n",i);
	    scanf("%d",&x);
		newnode->data=x;
		newnode->next=NULL;

		temp->next=newnode;
		temp=temp->next;

	}

}
void traverse()
{
	struct node *temp;
	temp=head;
	printf("Linked list is: \n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data );
		temp=temp->next;
	}
}
int main()
{
	int n;
	printf("Enter no. of nodes: ");
	scanf("%d",&n);
	create(n);
	traverse();
	return 0;
}