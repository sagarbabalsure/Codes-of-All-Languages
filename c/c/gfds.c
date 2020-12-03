#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<termios.h>
#define MAXPW 32
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
void login();
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
char name[20]="stationary";
char password[5]={0,0,0,0,0};
char pass[4];
int i,n,x,j,ch,l;
int s,e,point=0;
int flag=0;
ssize_t getpasswd (char **pw, size_t sz, int mask)
{
    if (!pw || !sz ) return -1;       /* validate input   */
    #ifdef MAXPW
        if (sz > MAXPW) sz = MAXPW;
    #endif

    if (*pw == NULL) {              /* reallocate if no address */
        void *tmp = realloc (*pw, sz * sizeof **pw);
        if (!tmp)
            return -1;
        memset (tmp, 0, sz);    /* initialize memory to 0   */
        *pw = tmp;
    }

    size_t idx = 0;         /* index, number of chars in read   */
    int c = 0;

    struct termios old_kbd_mode;    /* orig keyboard settings   */
    struct termios new_kbd_mode;

    if (tcgetattr (0, &old_kbd_mode)) { /* save orig settings   */
        fprintf (stderr, "%s() error: tcgetattr failed.\n", __func__);
        return -1;
    }   /* copy old to new */
    memcpy (&new_kbd_mode, &old_kbd_mode, sizeof(struct termios));

    new_kbd_mode.c_lflag &= ~(ICANON | ECHO);  /* new kbd flags */
    new_kbd_mode.c_cc[VTIME] = 0;
    new_kbd_mode.c_cc[VMIN] = 1;
    if (tcsetattr (0, TCSANOW, &new_kbd_mode)) {
        fprintf (stderr, "%s() error: tcsetattr failed.\n", __func__);
        return -1;
    }

    /* read chars from fp, mask if valid char specified */
    while (((c = fgetc (pass)) != '\n' && c != EOF && idx < sz - 1) ||
            (idx == sz - 1 && c == 127))
    {
        if (c != 127) {
            if (31 < mask && mask < 127)    /* valid ascii char */
                fputc (mask, stdout);
            (*pw)[idx++] = c;
        }
        else if (idx > 0) {         /* handle backspace (del)   */
            if (31 < mask && mask < 127) {
                fputc (0x8, stdout);
                fputc (' ', stdout);
                fputc (0x8, stdout);
            }
            (*pw)[--idx] = 0;
        }
    }
    (*pw)[idx] = 0; /* null-terminate   */

    /* reset original keyboard  */
    if (tcsetattr (0, TCSANOW, &old_kbd_mode)) {
        fprintf (stderr, "%s() error: tcsetattr failed.\n", __func__);
        return -1;
    }

    if (idx == sz - 1 && c != '\n') /* warn if pw truncated */
        fprintf (stderr, " (%s() warning: truncated at %zu chars.)\n",
                __func__, sz - 1);

    return idx; /* number of chars in passwd    */
}


int getMode()
{
    char username[20];
    printf("\t\t\tEnter username: _____\b\b\b\b\b");
    scanf("%s", name);

    char t;
    scanf("%c", &t);

    char pw[MAXPW] = {0};
    char *p = pw;
    ssize_t nchr = 0;

    printf ("\t\t\tEnter password: ");
    nchr = getpasswd (&p, MAXPW, '*');

    if(strcmp(username, "admin") == 0 && strcmp(p, "admin") == 0)
        return 1;
    
}
void main()
{
  getMode();
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
  int pos;
  temp=(struct stationary*)malloc(sizeof(struct stationary)*1);
  printf("Enter location you want to insert:");
  scanf("%d",&pos);
  

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
              break;

       case 2:
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
                    break;

             case 2:
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
            printf("\t%s\t%d\t%d\t%d",p->list,p->price,p->quantity,p->receipt_code);
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











