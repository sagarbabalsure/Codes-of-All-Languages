#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
node* head=NULL;
void push(int x)
{
	node* newnode = new node();
	newnode->data=x;
	newnode->next=head;
	head=newnode;
}
void pop()
{
	node* temp=head;
	head=temp->next;
	free(temp);
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
	push(4);
	push(7);
	push(24);
	traverse();
	pop();
	traverse();
	return 0;
}