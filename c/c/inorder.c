#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;
node *create()
{
	node *p;
	int x;
	printf("Enter data: \n");
	scanf("%d",&x);
	if(x==-1)
		return NULL;
	p=(struct node*)malloc(sizeof(struct node)*1);
	p->data=x;
	printf("Enter left child of %d:\n",x );
	p->left=create();
	printf("Enter right child oh %d\n",x );
	p->right=create();
	return p;
}
void inorder(node *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%d\n",t->data );
		inorder(t->right);
	}
}
void preorder(node *t)
{
	if(t==NULL)
		return;
	printf("%d\n",t->data );
	preorder(t->left);
	preorder(t->right);

}

int main()
{
	node *root;
	root=create();
	printf("Inorder tree is: \n");
	inorder(root);
	printf("preorder tree is: \n");
	preorder(root);
	return 0;
}