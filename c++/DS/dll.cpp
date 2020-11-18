#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node* prev;
};
node* head=NULL;
void insertAtBeg(int x)
{
	node* temp = new node();
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		node* temp1=head;
		temp1->prev=temp;
		temp->next=temp1;
		head=temp;
	}
}
void insertAtEnd(int x)
{
	node* temp = new node();
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	node* temp1=head;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=temp;
	temp->prev=temp1;
}
void traverse()
{
	node* temp=head;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}cout<<endl;
}
int main()
{
	insertAtBeg(4);
	insertAtBeg(7);
	insertAtBeg(14);
	traverse();
	insertAtEnd(20);
	insertAtEnd(25);
	traverse();
	return 0;
}