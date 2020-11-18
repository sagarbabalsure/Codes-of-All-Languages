#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* head=NULL;
void insert(int data)
{
	node* temp = new node();
	temp->data=data;
	temp->next=head;
	head=temp;
}
void print()
{
	node* temp=head;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}cout<<endl;
}
void insertAtEnd(int x)
{
	node* temp = new node();
	temp->data=x;
	temp->next=NULL;
	node* temp1 = head;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=temp;
}
void insertAtNNode(int n,int x)
{
	node*temp = new node();
	temp->data=x;
	temp->next=NULL;
	node* temp1 = head;
	for (int i = 0; i < n-2; ++i)
	{
		temp1=temp1->next;
	}
	temp->next=temp1->next;
	temp1->next=temp;
}
void deleteNode(int n)
{
	node* temp=head;
	if(n == 1)
	{
		int data=temp->data;
		head=temp->next;
		cout<<"deleted item: "<<data<<endl;
		free(temp);
	}
	else
	{
		for (int i = 0; i < n-2; ++i)
		{
			temp=temp->next;
		}
		node* temp1=temp->next;
		cout<<"deleted item: "<<temp1->data<<endl;
		temp->next=temp1->next;
		free(temp1);
	}
}
int main()
{
	insert(3);
	insert(5);
	insert(7);
	insert(9);
	print();
	insertAtEnd(10);
	insertAtEnd(15);
	insertAtNNode(4,20);
	print();
	deleteNode(3);
	print();
	return 0;
}