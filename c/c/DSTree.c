#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COUNT 10

struct stationary
{
    char list[20];
    int price;
    int quantity;
    int receipt_code;
    struct stationary *link;
}*start;
struct priceTree
{
  int price;
  struct priceTree *left;
  struct priceTree *right;
};

struct stationary* getNewNode();
struct stationary *create(struct stationary *start);
void display (struct stationary *start);
struct stationary *insert(struct stationary *start);
struct stationary *del(struct stationary *start,char item[]);
struct stationary *sort (struct stationary *start);
void *search(struct stationary *start,char item[]);
struct stationary *modify(struct stationary *start,char item[]);
void create_queue();
void display_queue();
void delete_queue();
struct stationary *front=NULL;
struct stationary *rear=NULL;
struct priceTree *node;
struct priceTree *root;
struct priceTree *getTree();
void sortTree(int arr[],int n);
struct priceTree *getnode(int x);
struct priceTree *BalancedBst(int arr[],int s,int e);
void print2DUtil(struct priceTree *root, int space);
void print2D(struct priceTree *root);
struct stationary *p,*q;
int i,n,x;
int s,e,flag=0;
void main()
{
    char item[20];
    int ch;
    struct stationary *start=NULL;

   printf("\t\t****************************************\n");
   printf("\t\t****************************************\n");
   printf("\t\t**   STATIONARY DISTRIBUTION SYSTEM   **\n");
   printf("\t\t****************************************\n");
   printf("\t\t****************************************\n");
   while(1)
  {
    printf(" 1) to create\n 2) to display.\n 3) to insert.\n 4) to delete. \n 5) to sort by price.\n 6) to search. \n 7) to modify. \n 8) create using queue.\n 9) display using queue.\n 10) delete using queue.\n 11) Create tree of price.\n 12) exit(0).\n\n ");
    printf("Enter choice-");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        start=create(start);
        break;
    case 2:
        display(start);
        break;
    case 3:
        start=insert(start);
        break;
    case 4:
        printf("Enter item you want to delete:");
        scanf("%s",item);
        start=del(start,item);
        break;
    case 5:
        sort(start);
        break;
    case 6:
        printf("Enter item you want to search:");
        scanf("%s",item);
        search(start,item);
        break;
    case 7:
        printf("Enter item you want to modify:");
        scanf("%s",item);
        start=modify(start,item);
        break;
    case 8:
           create_queue();
           break;
    case 9:
           display_queue();
           break;
    case 10:
           delete_queue();
           break;
    case 11:
           print2D(getTree(start));
           break;
    case 12:
           exit(0);
           break;
    default:
        printf("error!");

    }

  }
}
struct stationary *create(struct stationary *start)
{
    struct stationary *temp;
    printf("Enter no of type of items:");
    scanf("%d",&n);

    temp=start;
    for(i=0;i<n;i++)
     { temp=(struct stationary*)malloc(sizeof(struct stationary)*1);
       printf("\tenter product name:");
       scanf("%s",(temp->list));
       printf("\tenter price:");
       scanf("%d",&(temp->price));
       printf("\tenter quantity:");
       scanf("%d",&(temp->quantity));
       printf("\tenter receipt code:");
       scanf("%d",&(temp->receipt_code));
       printf("\n");


    if(start==NULL)
    {
     start=temp;
     temp->link=NULL;

    }

  else
  {
        p=start;
        while(p->link!=NULL)
        p=p->link;
        p->link=temp;
        temp->link=NULL;
  }
}
return start;
}

void display (struct stationary *start)
{
   if(start==NULL)
   {
       printf("\n*Order List is Empty*\n\n");
       return;
   }
  p=start;
  printf("\n\tItem\tPrice\tquantity\treceipt no.\n");
  while(p!=NULL)

    {

        printf("\n\t%s\t %d\t%d\t\t%d\n",p->list,p->price,p->quantity,p->receipt_code);
        p=p->link;

    }
}

struct stationary *insert(struct stationary *start)
{
  int pos,count=0;
  struct stationary *temp;
  temp=(struct stationary*)malloc(sizeof(struct stationary)*1);
  printf("Enter location you want to insert:");
  scanf("%d",&pos);
  if(pos <= n)
  {
      count++;
  }
  n=n+count;
  printf("%d",n);

    if(pos==1)
   {
    printf("\tenter product name:");
    scanf("%s",(temp->list));
    printf("\tenter price:");
    scanf("%d",&(temp->price));
    printf("\tenter quantity of product:");
    scanf("%d",&(temp->quantity));
    printf("\tenter receipt no. of product");
    scanf("%d",&(temp->receipt_code));
    temp->link=start;
    start=temp;

    return start;
  }
     p=start;

     for(i=1;i<pos-1 && p!=NULL;i++)
        p=p->link;
     if(p==NULL)
        printf("\n*less no of items*\n\n");

    else
    {   printf("\tenter product name:");
        scanf("%s",(temp->list));
        printf("\tenter price:");
        scanf("%d",&(temp->price));
        printf("\tenter quantity of product:");
        scanf("%d",&(temp->quantity));
        printf("\tenter receipt no. of product");
        scanf("%d",&(temp->receipt_code));
        temp->link=p->link;
         p->link=temp;
    }
   return start;
}

struct stationary *del(struct stationary *start,char item[])
{
  struct stationary *temp,*p;

  if(strcmp(start->list,item)==0)
  {
      temp=start;
      start=temp->link;
      free(temp);
      return start;
  }
      p=start;

      while(p->link!=NULL)
      { 
        if(strcmp(p->link->list,item)==0)
          {
            temp=p->link;
            p->link=temp->link;
            free(temp);
            return start;
      }
       p=p->link;
     }
     }

struct stationary *sort (struct stationary *start)
{
    struct stationary *temp;
    temp=(struct stationary*)malloc(sizeof(struct stationary)*1);
    for(p=start;p->link!=NULL;p=p->link)
    {
        for(q=p->link;q!=NULL;q=q->link)
        {

        if(p->price > q->price)
          {
             temp->price=p->price;
             p->price=q->price;
             q->price=temp->price;
             strcpy(temp->list,p->list);
             strcpy(p->list,q->list);
             strcpy(q->list,temp->list);

          }
       }
    }
}

void *search(struct stationary *start,char item[])
{

      if(strcmp(start->list,item)==0)
         {
       printf("\nITEM FOUND\n");
       printf("\nItem\tPrice\tquantity\treceipt_no.");
       printf("\n%s\t %d\t %d\t %d\n",start->list,start->price,start->quantity,start->receipt_code);
       flag++;
         }

       p=start;
       while(p->link!=NULL)
        {
            if(strcmp(p->link->list,item)==0)
          {
           printf("\n*ITEM FOUND\n");
           printf("\nItem\tPrice\tquantity\treceipt_no.");
           printf("\n%s\t %d\t %d\t %d\n",p->link->list,p->link->price,p->link->quantity,p->link->receipt_code);
          }
           p=p->link;
           flag++;
        }

        if(flag==0)
        printf("\n\nnot found\n\n");

}

struct stationary *modify(struct stationary *start,char item[])
{
    int choice;
    char ans1,ans2;
    int flag=0,chw=0;
    if(strcmp(start->list,item)==0)
     {
       printf("\nITEM FOUND\n");
       printf("\nItem\tPrice\tquantity\treceipt_no.");
       printf("\n%s\t %d\t %d\t %d\n",start->list,start->price,start->quantity,start->receipt_code);

     do
     {
       printf("enter:\n 1) to modify list name\n 2) to modify list price:");
       scanf("%d",&choice);
       switch (choice)
       {
       case 1:
        printf("enter new product name:");
        scanf("%s",(start->list));
        break;

       case 2:
        printf("enter new product price:");
        scanf("%d",&(start->price));
        break;

       }

       printf("press 1 to continue modifying:");
       scanf("%d",&chw);
      }while(chw==1);

            flag++;
            return start;
      }

       p=start;

       while(p->link!=NULL)
         {
            if(strcmp(p->link->list,item)==0)
          {
           printf("\n*ITEM FOUND\n");
           printf("\nItem\tPrice\tquantity\treceipt_no.");
           printf("\n%s\t %d\t %d\t %d\n",p->link->list,p->link->price,p->link->quantity,p->link->receipt_code);

            do
            {
            printf("enter:\n 1) to modify list name\n 2) to modify list price:");
            scanf("%d",&choice);

          switch (choice)
          {
           case 1:
           printf("enter new product name:");
           scanf("%s",(p->link->list));
           break;

           case 2:
           printf("enter new product price:");
           scanf("%d",&(p->link->price));
           break;

           }
           printf("press 1 to continue modifying:");
            scanf("%d",&chw);
            }while(chw==1);


           }
               p=p->link;
               flag++;
               return start;
        }

        if(flag==0)
        printf("\n\nnot found\n\n");
}

struct stationary* getNewNode()
{
    return (struct stationary*)malloc(sizeof(struct stationary));
}
void create_queue()
{
     struct stationary *temp;
     int q;
     printf("Enter no.of type of item:");
     scanf("%d",&n);
     for(int i=0;i<q;i++)
     {

    temp=getNewNode();
    printf("\tEnter product name:");
    scanf("%s",(temp->list));
    printf("\tEnter price:");
    scanf("%d",&(temp->price));
    printf("\tEnter quantity:");
    scanf("%d",&(temp->quantity));
    printf("\tEnter receipt_code:");
    scanf("%d",&(temp->receipt_code));

    if (rear==NULL)
    {
        rear= temp;
        front = temp;
        rear->link=NULL;
        continue;
    }
    rear->link=temp;
    rear=temp;
     }
}
void display_queue()
{
    struct stationary *p;

    if(front==NULL)
    {
        printf("\n No ITEM IN LIST\n");
    }
    else
    {
        p=front;
        printf("\n\tLIST \tPRICE \tQUANTITY \tRECEIPT CODE \n\n");
        while(p!=NULL)
           {
            printf("\t%s\t%d\t%d\t%d",p->list,p->price,p->quantity,p->receipt_code);
            printf("\n");
            p=p->link;
           }
    }
}
void delete_queue()
{
    struct stationary *temp;
    if(front==NULL)
    {
        printf("\n*Queue Underflow*\n");
    }
    else
    {
    temp=front;
    front=front->link;
    free(temp);
    }
}
struct priceTree *getTree(struct stationary *start)
{
  int arr[n];
  int point=0;
  struct stationary *temp=start;

  while(temp!=NULL)
  {
    arr[point++]=temp->price;
    temp=temp->link;
    
  }
    sortTree(arr,n);
    return BalancedBst(arr,0,n-1);
}
void sortTree(int arr[],int n)
{
  int temp,i,j;

  for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (n-1-i); j++)
        {
            if(arr[j] > arr[j+1]) //for decending order change "arr[j]<arr[j+1]"
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
struct priceTree *getnode(int x)
{
  struct priceTree *temp=(struct priceTree*)malloc(sizeof(struct priceTree));
  temp->price=x;
  temp->left=temp->right=NULL;
  return temp;
}
struct priceTree *BalancedBst(int arr[],int s,int e)
{
  if(s > e)
    return NULL;

  int mid=(s+e)/2;
  struct priceTree *root=getnode(arr[mid]);
  root->left=BalancedBst(arr,s,mid-1);
  root->right=BalancedBst(arr,mid+1,e);
  return root;
}

void print2DUtil(struct priceTree *root, int space)
{

    if (root == NULL)
        return;
    space+=COUNT;
    print2DUtil(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n\n", root->price);

    print2DUtil(root->left, space);
}

void print2D(struct priceTree *root)
{
    print2DUtil(root, 0);
}



/*  OUTPUT
    ****************************************
    ****************************************
    **   STATIONARY DISTRIBUTION SYSTEM   **
    ****************************************
    ****************************************
 1) to create
 2) to display.
 3) to insert.
 4) to delete. 
 5) to sort by price.
 6) to search. 
 7) to modify. 
 8) create using queue.
 9) display using queue.
 10) delete using queue.
 11) Create tree of price.
 12) exit(0).

 Enter choice-1
Enter no of type of items:2
  enter product name:book
  enter price:50
  enter quantity:21
  enter receipt code:1

  enter product name:pen
  enter price:25
  enter quantity:22
  enter receipt code:2

 1) to create
 2) to display.
 3) to insert.
 4) to delete. 
 5) to sort by price.
 6) to search. 
 7) to modify. 
 8) create using queue.
 9) display using queue.
 10) delete using queue.
 11) Create tree of price.
 12) exit(0).

 Enter choice-2

  Item  Price quantity  receipt no.

  book   50      21         1

  pen    25      22         2
 1) to create
 2) to display.
 3) to insert.
 4) to delete. 
 5) to sort by price.
 6) to search. 
 7) to modify. 
 8) create using queue.
 9) display using queue.
 10) delete using queue.
 11) Create tree of price.
 12) exit(0).

 Enter choice-3
Enter location you want to insert:2
3 enter product name:file
  enter price:30
  enter quantity of product:66
  enter receipt no. of product3
 1) to create
 2) to display.
 3) to insert.
 4) to delete. 
 5) to sort by price.
 6) to search. 
 7) to modify. 
 8) create using queue.
 9) display using queue.
 10) delete using queue.
 11) Create tree of price.
 12) exit(0).

 Enter choice-2

  Item  Price quantity  receipt no.

  book   50      21         1

  file   30      66         3

  pen    25      22         2
 1) to create
 2) to display.
 3) to insert.
 4) to delete. 
 5) to sort by price.
 6) to search. 
 7) to modify. 
 8) create using queue.
 9) display using queue.
 10) delete using queue.
 11) Create tree of price.
 12) exit(0).

 Enter choice-5
 1) to create
 2) to display.
 3) to insert.
 4) to delete. 
 5) to sort by price.
 6) to search. 
 7) to modify. 
 8) create using queue.
 9) display using queue.
 10) delete using queue.
 11) Create tree of price.
 12) exit(0).

 Enter choice-2

  Item  Price quantity  receipt no.

  pen    25     21        1

  file   30     66        3

  book   50     22        2
 1) to create
 2) to display.
 3) to insert.
 4) to delete. 
 5) to sort by price.
 6) to search. 
 7) to modify. 
 8) create using queue.
 9) display using queue.
 10) delete using queue.
 11) Create tree of price.
 12) exit(0).

 Enter choice-6
Enter item you want to search:pen

ITEM FOUND

Item  Price quantity  receipt_no.
pen  25  21  1
 1) to create
 2) to display.
 3) to insert.
 4) to delete. 
 5) to sort by price.
 6) to search. 
 7) to modify. 
 8) create using queue.
 9) display using queue.
 10) delete using queue.
 11) Create tree of price.
 12) exit(0).

 Enter choice-11

          50


30


          25

 1) to create
 2) to display.
 3) to insert.
 4) to delete. 
 5) to sort by price.
 6) to search. 
 7) to modify. 
 8) create using queue.
 9) display using queue.
 10) delete using queue.
 11) Create tree of price.
 12) exit(0).

 Enter choice-
 */









