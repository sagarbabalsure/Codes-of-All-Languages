#include<stdio.h>
#include<stdlib.h>
struct node
{
int key;
struct node *left, *right;
};
struct node *newNode(int item)
{
struct node *temp=(struct node *)malloc(sizeof(struct node));
temp->key=item;
temp->left=temp->right=NULL;
return temp;
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
struct node* insert(struct node* node, int key)
{
if (node == NULL) return newNode(key);
if (key < node->key)
node->left=insert(node->left, key);
else
node->right=insert(node->right, key);
return node;
}
struct node * minValueNode(struct node* node)
{
struct node* current = node;
while (current->left != NULL)
current = current->left;
return current;
}
struct node* deleteNode(struct node* root, int key)
{
if (root == NULL) return root;
if (key < root->key)
root->left = deleteNode(root->left, key);
else if (key > root->key)
root->right = deleteNode(root->right, key);
else
{
if (root->left == NULL)
{
struct node *temp = root->right;
free(root);
return temp;
}
else if (root->right == NULL)
{
struct node *temp = root->left;
free(root);
return temp;
}
struct node* temp = minValueNode(root->right);
root->key = temp->key;
root->right = deleteNode(root->right, temp->key);
}
return root;
}
void print2DUtil(struct node *root, int space)
{
 int COUNT;
   if (root == NULL)
        return;
    space+=COUNT;
    print2DUtil(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    print2DUtil(root->left, space);
}
int main()
{
int ch,x,space;
struct node *root = NULL;

while(1)
{
printf("Enter choice: ");
scanf("%d",&ch);
switch(ch)
{
 case 1:
        printf("Enter data: ");
        scanf("%d",&x);
        root=insert(root,x);
        break;
 case 2:
       printf("delete data: ");
        scanf("%d",&x);
       root=deleteNode(root,x);
       break;
 case 3:
       printf("Inorder :");
       inorder(root);
       break;
 case 4:
       print2DUtil(root,space);
       break;
 case 5:
       exit(0);
}
}
return 0;
}
