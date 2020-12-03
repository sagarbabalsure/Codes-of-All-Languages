#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *left;
	struct node *right;
};
struct node *newnode(int item)
{
	struct node *p=(struct node*)malloc(sizeof(struct node)*1);
	p->key=item;
	p->left=p->right=NULL;
	return p;
}
struct node *insert(struct node *node,int key)
{
	if(node==NULL)
		return newnode(key);
	if(key < node->key)
		node->left=insert(node->left,key);
	else if(key > node->key)
		node->right=insert(node->right,key);
	return node;
}
void inorder(struct node *root)
{
if (root != NULL)
{
inorder(root->left);
printf("%d ", root->key);
inorder(root->right);
}
}
int main()
{
	int x,ch;
	struct node *root=NULL;
	while(1)
   {
	printf("ENter the choice: \n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		       printf("Enter key: \n");
		       scanf("%d",&x);
		       root=insert(root,x);
		       break;
		/*case 2:
		       printf("Enter key: \n");
		       scanf("%d",&x);
		       delete(root,x);
		       break;*/
		case 2:
		       printf("inorder tree: \n");
		       inorder(root);
               break;
        case 3:
              exit(0);
                     
 	}
 }
 return 0;

}