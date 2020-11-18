#include<stdio.h>
#include<stdlib.h>
struct node
{
 int key;
 struct node *left, *right;
};
struct node *newNode(int item)
{
struct node *temp =  (struct node *)malloc(sizeof(struct node));
temp->key = item;
temp->left = temp->right = NULL;
return temp;
}
 
// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
 if (root != NULL)
 {
  inorder(root->left);
  printf("%d ", root->key);
  inorder(root->right);
 }
}
