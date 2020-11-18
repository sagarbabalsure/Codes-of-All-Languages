#include<iostream>
using namespace std;
struct node{
	int data;
	node* link;
};
node* head;
void InsertAtBeg(int x)
{
	node* temp=new node();
	temp->data=x;
	temp->link=NULL;
	if(head==NULL){
		head=temp;
		return;
	}
	temp->link=head;
	head=temp;
}
void InsertAtEnd(int x)
{
	node* temp=new node();
	temp->data=x;
	temp->link=NULL;
	if(head==NULL)
	{
		head=temp;
		return;
	}
	node* temp1=head;
	while(temp1->link!=NULL)
	{
		temp1=temp1->link;
	}
	temp1->link=temp;

}
void print()
{
	node* temp=head;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<'\n';
}
void RecursivePrint(node* p)
{
	if(p==NULL) return ;
	RecursivePrint(p->link);
	cout<<p->data;
}
void DeleteNode(int n)
{
	node* temp1=head;
	for (int i = 0; i < n-2; ++i)
	{
		temp1=temp1->link;
	}
	node* temp2=temp1->link;
	temp1->link=temp2->link;
	free(temp2);
}
int main()
{
	head=NULL;
	int n,x,y;
	cout<<"ENter how many numbers: ";
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cout<<"Enter number:";
		cin>>x;
		InsertAtBeg(x);
		cout<<"Enter number1: ";
		cin>>y;
		InsertAtEnd(y);
		print();
	}
	int N;
	cin>>N;
	DeleteNode(N);
	print();
	RecursivePrint(head);

}