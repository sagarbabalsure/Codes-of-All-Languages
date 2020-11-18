#include<iostream>
using namespace std;
#include<queue>
struct node{
	int data;
	node* left;
	node* right;
};
node* GetNewNode(int data)
{
	node* temp=new node();
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
node* Insert(node* root,int data)
{
	if(root==NULL)
	{
		root=GetNewNode(data);
	}
	else if(data<=root->data)
	{
		root->left=Insert(root->left,data);
	}
	else{
		root->right=Insert(root->right,data);
	}
	return root;
}
int search(node* root,int n)
{
	if(root==NULL)return false;
	else if(n==root->data)return true;
	else if(n<root->data)return (search(root->left,n));
	else return (search(root->right,n));
}
void traverse(node* root)
{
	if(root==NULL)return ;
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node* temp=q.front();
		cout<<temp->data<<" ";
		if(temp->left!=NULL)q.push(temp->left);
		if(temp->right!=NULL)q.push(temp->right);
		q.pop();
	}
}
node* findmin(node* p)
{
	while(p->left!=NULL)
	{
		p=p->left;
	}
	return p;
}
node* DeleteNode(node* root,int d)
{
	if(root==NULL)return root;
	else if(d<root->data)root->left=DeleteNode(root->left,d);
	else if(d>root->data)root->right=DeleteNode(root->right,d);
	else{
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			root=NULL;
		}
		else if(root->left==NULL)
		{
			node* temp=root;
			root=temp->right;
			delete temp;
		}
		else if(root->right==NULL)
		{
			node* temp=root;
			root=temp->left;
			delete temp;
		}
		else
		{
			node* temp=findmin(root->right);
			root->data=temp->data;
			root->right=DeleteNode(root->right,temp->data);

		}
	}return root;

}
int main()
{
	node* root=NULL;
	root=Insert(root,15);
	root=Insert(root,10);
	root=Insert(root,20);
	root=Insert(root,8);
	int num;
	cout<<"Enter number to be find in tree: ";
	cin>>num;
	if(search(root,num)==true)cout<<"found";
	else cout<<"not found";
	traverse(root);
	int d;
	cout<<"Enter number to delete: ";
	cin>>d;
	root=DeleteNode(root,d);
	traverse(root);

}