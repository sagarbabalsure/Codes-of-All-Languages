#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COUNT 10
struct Node
{
    char name[20] ;
    char email[20];
    int age;
    char username[20];
    char password[20];
    struct node *left;
    struct node *right;

};
struct Node *node ;
struct Node *create()
{
    struct Node *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);

    if(x==-1)
        return NULL;

    p=(struct Node*)malloc(sizeof(struct Node)*100);
    p->age=x;

    printf("Enter left child of %d:\n",x);
    p->left=create();

    printf("Enter right child of %d:\n",x);
    p->right=create();

    return p;
}

void print2DUtil(struct Node *root, int space)
{

    if (root == NULL)
        return;
    space+=COUNT;
    print2DUtil(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->age);

    print2DUtil(root->left, space);
}

void print2D(struct Node *root)
{
    print2DUtil(root, 0);
}
int main()
{
    int a ;

    struct Node *root ;
    root=create(a) ;


    print2D(root);

    return 0;
}
