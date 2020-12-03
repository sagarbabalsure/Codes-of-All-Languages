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
struct stationary *insert(struct stationary *start);
struct stationary *del(struct stationary *start,char item[]);
struct stationary *sort (struct stationary *start);
struct stationary *modify(struct stationary *start,char item[]);
void display (struct stationary *start);
void *search(struct stationary *start,char item[]);
void create_queue();
void display_queue();
void delete_queue();
struct stationary *front=NULL;
struct stationary *rear=NULL;
struct priceTree *node;
struct priceTree *root;
struct priceTree *getTree();
struct priceTree *getnode(int x);
struct priceTree *BalancedBst(int arr[],int s,int e);
void sortTree(int arr[],int n);
void print2DUtil(struct priceTree *root, int space);
void print2D(struct priceTree *root);
struct stationary *p,*q,*temp;
char item[20];
int i,n,x,j,ch,l;
int s,e,point=0;
int flag=0;
void main()
{
   struct stationary *start=NULL;

   printf("\t\t****************************************\n");
   printf("\t\t****************************************\n");
   printf("\t\t**   STATIONARY DISTRIBUTION SYSTEM   **\n");
   printf("\t\t****************************************\n");
   printf("\t\t****************************************\n");
  while(1)
    {
     printf(" 1) to create\n 2) to display.\n 3) to insert.\n 4) to delete. \n 5) to sort by price.\n 6) to search. \n 7) to modify. \n 8) create using queue.\n 9) display using queue.\n 10) delete using queue.\n 11) Create tree of price.\n 12) exit(0).\n\n ");
     printf("Enter your choice-");
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
     { 
       temp=(struct stationary*)malloc(sizeof(struct stationary)*1);
       while(1)
       {
        printf("\tenter product name(Length 1 to 10):");
        scanf("%s",(temp->list));
        l=strlen(temp->list);
        if(l > 10 )
        {
          printf("\tPlease enter less characters in list name\n");
        }
        else
           break;
       }

       do{
           printf("\tenter price (1 to 999):");
           scanf("%d",&(temp->price));
          if(temp->price > 1 && temp->price < 999)
          {
            break;
          }
          else
          {
            printf("\tPlease enter less price\n");
          }
         }while(1);

       do{
          printf("\tenter quantity(1 to 500):");
          scanf("%d",&(temp->quantity));
            if(temp->quantity > 1 && temp->quantity < 500)
          {
            break;
          }
          else
          {
            printf("\tPlease enter less quantity\n");
          }
        }while(1);

       do{

           printf("\tenter receipt code(1 to 200):");
           scanf("%d",&(temp->receipt_code));
           if(temp-> receipt_code > 0 && temp-> receipt_code < 200)
          {
            break;
          }
          else
          {
            printf("\tSORRY..not available Please enter receipt_code between(1 to 200)\n");
          }
        }while(1);
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
      printf("\n\t%s\t %d\t%d\t\t%d",p->list,p->price,p->quantity,p->receipt_code);
      p=p->link;
    }
    printf("\n");
}

struct stationary *insert(struct stationary *start)
{
  struct stationary *temp;
  int pos,count=0;
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
      while(1)
       {
        printf("\tenter product name(Length 1 to 10):");
        scanf("%s",(temp->list));
        l=strlen(temp->list);
        if(l > 10 )
        {
          printf("\tPlease enter less characters in list name\n");
        }
        else
           break;
       }

       do{
           printf("\tenter price(1 to 999):");
           scanf("%d",&(temp->price));
          if(temp->price > 1 && temp->price < 999)
          {
            break;
          }
          else
          {
            printf("\tPlease enter less price\n");
          }
        }while(1);

       do{
          printf("\tenter quantity(1 to 500):");
          scanf("%d",&(temp->quantity));
            if(temp->quantity > 1 && temp->quantity < 500)
          {
            break;
          }
          else
          {
            printf("\tPlease enter less quantity\n");
          }
        }while(1);

      do{
           printf("\tenter receipt code(1 to 200):");
           scanf("%d",&(temp->receipt_code));
           if(temp-> receipt_code > 0 && temp-> receipt_code < 200)
          {
            break;
          }
          else
          {
            printf("\tSORRY..not available Please enter receipt_code between(1 to 200)\n");
          }
        }while(1);
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
    {
       while(1)
       {
        printf("\tenter product name(Length 1 to 10):");
        scanf("%s",(temp->list));
        l=strlen(temp->list);
        if(l > 10 )
        {
          printf("\tPlease enter less characters in list name\n");
        }
        else
           break;
       }

         do{
           printf("\tenter price(1 to 999):");
           scanf("%d",&(temp->price));
          if(temp->price > 1 && temp->price < 999)
          {
            break;
          }
          else
          {
            printf("\tPlease enter less price\n");
          }
        }while(1);

       do{
          printf("\tenter quantity(1 to 500):");
          scanf("%d",&(temp->quantity));
            if(temp->quantity > 1 && temp->quantity < 500)
          {
            break;
          }
          else
          {
            printf("\tPlease enter less quantity\n");
          }
        }while(1);

       do{
           printf("\tenter receipt code(1 to 200):");
           scanf("%d",&(temp->receipt_code));
           if(temp-> receipt_code > 0 && temp-> receipt_code < 200)
          {
            break;
          }
          else
          {
            printf("\tSORRY..not available Please enter receipt_code between(1 to 200)\n");
          }
        }while(1);

         temp->link=p->link;
         p->link=temp;
    }
   return start;
}

struct stationary *del(struct stationary *start,char item[])
{
  struct stationary *temp;
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
    char ans1,ans2;
    int chw=0;
    if(strcmp(start->list,item)==0)
     {
       printf("\nITEM FOUND\n");
       printf("\nItem\tPrice\tquantity\treceipt_no.");
       printf("\n%s\t %d\t %d\t %d\n",start->list,start->price,start->quantity,start->receipt_code);

     do
     {
       printf("enter:\n 1) to modify list name\n 2) to modify list price:");
       scanf("%d",&ch);
       switch (ch)
       {
       case 1:
             while(1)
             {
              printf("\tenter product name(Length 1 to 10):");
              scanf("%s",(start->list));
              l=strlen(start->list);
              if(l > 10 )
              {
                printf("\tPlease enter less characters in list name\n");
              }
              else
              {
                 break;
              }
             }
              break;

       case 2:
              do{
                 printf("\tenter price(1 to 999):");
                 scanf("%d",&(start->price));
                if(start->price > 1 && start->price < 999)
                {
                  break;
                }
                else
                {
                  printf("\tPlease enter less price\n");
                }
              }while(1);
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
              scanf("%d",&ch);

          switch (ch)
          {
             case 1:
                     while(1)
                     {
                      printf("\tenter product name(Length 1 to 10):");
                      scanf("%s",(p->link->list));
                      l=strlen(p->link->list);
                      if(l > 10 )
                      {
                        printf("\tPlease enter less characters in list name\n");
                      }
                      else
                      {
                         break;
                      }
                     }
                    break;

             case 2:
                   do{
                       printf("\tenter price(1 to 999):");
                       scanf("%d",&(p->link->price));
                      if(p->link->price > 1 && p->link->price < 999)
                      {
                        break;
                      }
                      else
                      {
                        printf("\tPlease enter less price\n");
                      }
                    }while(1);
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
  int q;
  struct stationary *temp;
  printf("Enter no.of type of item:");
  scanf("%d",&q);
  for(int i=0;i<q;i++)
     {
        temp=getNewNode();
        while(1)
       {
        printf("\tenter product name(Length 1 to 10):");
        scanf("%s",(temp->list));
        l=strlen(temp->list);
        if(l > 10 )
        {
          printf("\tPlease enter less characters in list name\n");
        }
        else
        {
           break;
        }
       }

       do{
           printf("\tenter price(1 to 999):");
           scanf("%d",&(temp->price));
          if(temp->price > 1 && temp->price < 999)
          {
            break;
          }
          else
          {
            printf("\tPlease enter less price\n");
          }
        }while(1);
        
       do{
          printf("\tenter quantity(1 to 500):");
          scanf("%d",&(temp->quantity));
            if(temp->quantity > 1 && temp->quantity < 500)
          {
            break;
          }
          else
          {
            printf("\tPlease enter less quantity\n");
          }
        }while(1);

       do{

           printf("\tenter receipt code(1 to 200):");
           scanf("%d",&(temp->receipt_code));
           if(temp-> receipt_code > 0 && temp-> receipt_code < 200)
          {
            break;
          }
          else
          {
            printf("\tSORRY..not available Please enter receipt_code between(1 to 200)\n");
          }
        }while(1);
        printf("\n");

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
            printf("\t%s\t%d\t%d\t\t\t%d",p->list,p->price,p->quantity,p->receipt_code);
            printf("\n");
            p=p->link;
           }
    }
}
void delete_queue()
{
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
  int temp;
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

/*output
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

 Enter your choice-1
Enter no of type of items:3
  enter product name(Length 1 to 10):book
  enter price (1 to 999):50
  enter quantity(1 to 500):25
  enter receipt code(1 to 200):1

  enter product name(Length 1 to 10):pen
  enter price (1 to 999):1254
  Please enter less price
  enter price (1 to 999):15
  enter quantity(1 to 500):555
  Please enter less quantity
  enter quantity(1 to 500):20
  enter receipt code(1 to 200):255
  SORRY..not available Please enter receipt_code between(1 to 200)
  enter receipt code(1 to 200):2

  enter product name(Length 1 to 10):marker
  enter price (1 to 999):12
  enter quantity(1 to 500):30
  enter receipt code(1 to 200):3

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

 Enter your choice-2

  Item  Price quantity  receipt no.

  book   50     25        1
  pen    15     20        2
  marker 12     30        3
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

 Enter your choice-3
Enter location you want to insert:2
4
  enter product name(Length 1 to 10):chart
  enter price(1 to 999):5
  enter quantity(1 to 500):21
  enter receipt code(1 to 200):4
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

 Enter your choice-2

  Item  Price quantity  receipt no.

  book    50     25        1
  chart   5      21        4
  pen     15     20        2
  marker  12     30        3
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

 Enter your choice-5
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

 Enter your choice-2

  Item  Price quantity  receipt no.

  chart  5      25        1
  marker 12     21        4
  pen    15     20        2
  book   50     30        3
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

 Enter your choice-6
Enter item you want to search:pen

*ITEM FOUND

Item  Price quantity  receipt_no.
pen    15     20         2
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

 Enter your choice-8
Enter no.of type of item:2
  enter product name(Length 1 to 10):book
  enter price(1 to 999):26
  enter quantity(1 to 500):29
  enter receipt code(1 to 200):5

  enter product name(Length 1 to 10):asdfghjkloiuytre
  Please enter less characters in list name
  enter product name(Length 1 to 10):pencil
  enter price(1 to 999):1256
  Please enter less price
  enter price(1 to 999):8
  enter quantity(1 to 500):589
  Please enter less quantity
  enter quantity(1 to 500):52
  enter receipt code(1 to 200):6

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

 Enter your choice-9

  LIST  PRICE   QUANTITY  RECEIPT CODE 

  book   26       29        5
  pencil 8        52        6
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

 Enter your choice-11

          15


12


          5

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

*/










