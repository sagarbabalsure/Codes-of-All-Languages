
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COUNT 15

struct social_net
{
    char name[20];
    char password[20] ;
    char usernameL[20];
    char passwordL[20];
     char email[20];
    char username[20] ;
    int age ;
    struct social_net *connect;
    struct social_net *left;
    struct social_net *right;
} *start;


struct social_net *node ;
struct social_net *root ;

struct social_net *create(struct social_net *start);
void display (struct social_net *start);

struct social_net *sort (struct social_net *start);
void *search(struct social_net *start,char account[]);

struct social_net *insert(struct social_net *start);
struct social_net *del(struct social_net *start,char account[]);

struct social_net *modify(struct social_net *start,char account[]);
void del_queue();

struct social_net*front=NULL;
struct social_net*rear=NULL;

void create_queue();
void display_queue();

void insert_queue() ;
struct social_net *createt() ;


int k ;
int n, j ;
int a[20] ;

void main ()
{

    char account[50];
    int ch ;
    struct social_net *start=NULL;
    printf ("\n") ;
    printf ("\n") ;
    printf ("\n") ;
    printf ("\n") ;
    printf("\t\t\t\t**************************************************\n");
    printf("\t\t\t\t//////////////////////////////////////////////////\n");
    printf("\t\t\t\t<<<<<<<<           HELLO !          >>>>>>>>\n");
    printf("\t\t\t\t<<<<<<<<  WELCOME To The SMARTCOMM  >>>>>>>>\n");
    printf("\t\t\t\t                - Your Best Social Networking Platform .\n");

    printf("\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
    printf("\n\t\t\t\t*************************************************\n");
    while(1)
    {
        printf("..................................................................................\n");
        printf("..................................................................................\n");
        printf ("Select : \n" );
        printf("1.Sign Up( Prime account ).\n");
        printf("2.Display details( Prime account ).\n") ;
        printf("3.Sort( only for Prime Account ).\n") ;
        printf("4.Search ( only for Prime Account ).\n") ;
        printf("5.Insert( Prime Account ).\n") ;
        printf("6.Delete ( Prime Account ).\n") ;
        printf("7. Modify ( only for Prime Account ).\n") ;
        printf("8.Sign Up ( Regular User Account ).\n") ;
        printf("9.Display details ( Regular User Account ).\n") ;
        printf("10.Delete ( Regular User Account ).\n") ;
        printf("11.Insert ( Regular User Account ).\n") ;
        printf("12.Form Family age Tree .\n") ;
        scanf ("%d",&ch ) ;
        switch (ch)
        {
        case 1:
            start =create(start);
            break;


        case 2 :
            printf("\t*****before sorting*******\n\n");
            display(start);
            break;

        case 3 :
            sort(start);
            printf("\t*******after sorting*******\n\n");
            display(start) ;
            break;

        case 4 :
             printf("Enter the Name of the Friend you want to search:");
        scanf("%s",account);
            search (start,account) ;
            break ;

        case 5 :
            start=insert(start);
            break;

        case 6 :
            printf("//////////////////////////////////////////////////////////////////////////////////\n");
            printf("Enter account you want to delete:");
            scanf("%s",account);
            printf("//////////////////////////////////////////////////////////////////////////////////\n");
            start=del(start,account);
            break;

        case 7:
            printf("Enter account you want to modify:");
            scanf("%s",account);
            start=modify(start,account);
            break;

        case 8:
           create_queue();
           break;

        case 9:
           display_queue();
           break;

        case 10:
            del_queue();
            break;

        case 11 :
            insert_queue() ;
            break ;

        case 12 :
            printf("\n How much older are you ?\n") ;
            root=createt(k) ;
            print2D(root);
            return 0;
            break ;


         default :
            printf("wrong choice");
            exit(0);

        }

    }

}

struct social_net *create(struct social_net* start)
{

    struct social_net *p, *temp;
    printf ("Enter the number of accounts : \n ");
    scanf ("%d",&n) ;
    temp = start;
    for (int i=0 ; i<n ; i++)
    {
        temp = (struct social_net*)malloc(sizeof(struct social_net));
        printf("//////////////////////////////////////////////////////////////////////////////////\n");
        printf("\n \t Enter your name : ");
        scanf(" \t\t%s",(temp->name));
        printf("\n \t Enter Email ID : ");
        scanf(" \t\t%s",(temp->email));
        printf("\n \t Enter your age : ") ;
        scanf ("\t\t%d",&(temp->age)) ;

        if(start == NULL)
        {
            start = temp;
            temp->connect = NULL;

        }
        else
        {
            p=start;
            while(p->connect!=NULL)
                p=p->connect;
            p->connect=temp;
            temp->connect=NULL;
        }
        printf("\n \t Enter your user  name :");
        scanf("\t \t%s",temp->username);
        printf("\n \t Enter password : ");
        scanf("\t \t%s",temp->password);
    }

    return start;
    printf ("Hope You are Enjoying SMARTCOMM . \n Try out some other Function . \n") ;

}
void display(struct social_net *start)
{

    printf("\tName  \t \tAge   \t\tEmail   \t\tUsername \n");
    printf("\n");
    struct social_net *p;

    p = start;
    while(p!=NULL)

    {

        printf("\t");
        printf("%s\t\t",p->name);

        printf("%d\t\t",p->age);

        printf("%s\t\t",p->email);

        printf("%s\t\t",p->username);
        printf("\n");
        p=p->connect;

    }
    printf("\n");




    printf ("Hope You are Enjoying SMARTCOMM . \n Try out some other Function . \n") ;

}
struct social_net *sort(struct social_net *start)
{

    struct social_net *p, *q, *temp;
    temp=(struct social_net*)malloc(sizeof(struct social_net)*5);

    for(p=start; p->connect!=NULL; p=p->connect)
    {
        for(q=p->connect; q!=NULL; q=q->connect)
        {

            if(p->age > q->age)
            {
                temp->age=p->age;
                p->age=q->age;
                q->age=temp->age;
                strcpy(temp->name,p->name);
                strcpy(p->name,q->name);
                strcpy(q->name,temp->name);
                strcpy(temp->username,p->username);
                strcpy(p->username,q->username);
                strcpy(q->username,temp->username);
                strcpy(temp->email,p->email);
                strcpy(p->email,q->email);
                strcpy(q->email,temp->email);



            }
        }
    }
}
void *search(struct social_net *start,char account[])
{

  struct social_net *p;
  int flag=0;


      if(strcmp(start->name,account)==0)
         {
        printf("\n*account FOUND\n");
           printf("..................................................................................\n");
           printf("\n\t\tname : ");
           printf("%s\n",start->name);

           printf("\t\tage : ");
           printf("%d\n",start->age);

           printf("\t\temail : ");
           printf("%s\n",start->email);

           printf("\t\tusername : ");
           printf("%s\n",start->username);
       flag++;
         }

       p=start;
       while(p->connect!=NULL)
        {
            if(strcmp(p->connect->name,account)==0)
          {
           printf("\n*account FOUND\n");
           printf("..................................................................................\n");
           printf("\n\t\tname : ");
           printf("%s\n",p->connect->name);

           printf("\t\tage : ");
           printf("%d\n",p->connect->age);

           printf("\t\temail : ");
           printf("%s\n",p->connect->email);

           printf("\t\tusername : ");
           printf("%s\n",p->connect->username);
           printf("..................................................................................\n");
          }
           p=p->connect;
           flag++;
        }
        if(flag==0)
        printf("\n\nnot found\n\n");

}
struct social_net *insert(struct social_net *start)
{

    int pos;
    struct social_net *p,*temp;
    temp=(struct social_net*)malloc(sizeof(struct social_net)*1);
    printf("Enter location you want to insert:");
    scanf("%d",&pos);

    if(pos==1)
    {
        printf("//////////////////////////////////////////////////////////////////////////////////\n");
        printf("\t\t\nEnter  name:");
        scanf("%s",(temp->name));
        printf("\t\t\nEnter age :");
        scanf("%d",&(temp->age));
        printf("\t\t\nEnter email:");
        scanf("%s",(temp->email));
        printf("\t\t\nEnter Username :");
        scanf("%s",(temp->username ));
        printf("\t\t\nEnter Password:");
        scanf("%s",(temp->password));
        temp->connect=start;
        start=temp;

        return start;
    }
    p=start;
    for(int i=1; i<pos-1 && p!=NULL; i++)
        p=p->connect;
    if(p==NULL)
        printf("\n*less no of accounts*\n\n");

    else
    {
        printf("//////////////////////////////////////////////////////////////////////////////////\n");
        printf("\t\t\nEnter  name:");
        scanf("%s",(temp->name));
        printf("\t\t\nEnter age:");
        scanf("%d",&(temp->age));
        printf("\t\t\nEnter email:");
        scanf("%s",(temp->email));
        printf("\t\t\nEnter Username :");
        scanf("%s",(temp->username));
        printf("\t\t\nEnter Password:");
        scanf("%s",(temp->password));
        temp->connect=p->connect;
        p->connect=temp;
    }
    return start;
}

struct social_net *del(struct social_net *start,char account[])
{

  struct social_net *temp,*p;

  if(strcmp(start->name,account)==0)
  {
      temp=start;
      start=temp->connect;
      free(temp);
      return start;
  }
      p=start;
      while(p->connect!=NULL)
      { if(strcmp(p->connect->name,account)==0)
          {
            temp=p->connect;
            p->connect=temp->connect;
            free(temp);
            return start;
      }
     p=p->connect;
     }
     }

struct social_net *modify(struct social_net *start,char account[])
{

         struct social_net *p;
    int choice;
    char ans1,ans2;
    int flag=0,chs=0;


      if(strcmp(start->name,account)==0)
     {

           printf("\n*account FOUND\n");
           printf("..................................................................................\n");
           printf("\n\t\tname : ");
           printf("%s\n",p->connect->name);

           printf("\t\tage : ");
           printf("%d\n",p->connect->age);

           printf("\t\temail : ");
           printf("%s\n",p->connect->email);

           printf("\t\tusername : ");
           printf("%s\n",p->connect->username);
           printf("..................................................................................\n");
     do
     {



       printf("enter:\n 1.to modify name name\n 2. to modify name age: \n 3. To modify email\n 4. TO modify username\n");
       scanf("%d",&choice);
       printf("//////////////////////////////////////////////////////////////////////////////////\n");
       switch (choice)
       {
       case 1:
        printf("\t\t\nEnter new  name:");
        scanf("%s",(start->name));
        break;
       case 2:
        printf("\t\t\nEnter new  age:");
        scanf("%d",&(start->age));
        break;

        case 3:
        printf("\t\t\nEnter new  email:");
        scanf("%s",&(start->email));
        break;

        case 4:
        printf("\t\t\nEnter new  username:");
        scanf("%s",&(start->username));
        break;


        default :
            printf("Please enter correct choice to proceed \n");
            break;

       }

       printf("\n\t\t Press 0 to return to main menu \n\t\t press 1 to continue modifying:");
       scanf("%d",&chs);

      }while(chs==1);

            flag++;
            return start;
      }

       p=start;
       while(p->connect!=NULL)
         {
            if(strcmp(p->connect->name,account)==0)
          {
           printf("\n*account FOUND\n");
           printf("..................................................................................\n");
           printf("\n\t\tname : ");
           printf("%s\n",p->connect->name);

           printf("\t\tage : ");
           printf("%d\n",p->connect->age);

           printf("\t\temail : ");
           printf("%s\n",p->connect->email);

           printf("\t\tusername : ");
           printf("%s\n",p->connect->username);
           printf("..................................................................................\n");

            do
            {
            printf("enter:\n  1.To modify name name\n  2.To modify name age\n  3.To modify email\n  4.TO modify username\n");
            scanf("%d",&choice);

          switch (choice)
          {
           case 1:
           printf("\t\t\nEnter new name name:");
           scanf("%s",(p->connect->name));
           break;
           case 2:
           printf("\t\t\nEnter new name age:");
           scanf("%d",&(p->connect->age));
           break;

           case 3:
           printf("\t\t\nEnter new  email:");
           scanf("%s",&(p->connect->email));
           break;

          case 4:
          printf("\t\t\nEnter new  username:");
          scanf("%s",&(p->connect->username));
          break;


        default :
            printf("Please enter correct choice to proceed \n");
            break;

           }printf("\n Press 0 to return to main menu \n press 1 to continue modifying:");
            scanf("%d",&chs);
            }while(chs==1);


           }
               p=p->connect;
               flag++;
               return start;
        }

        if(flag==0)
        printf("\n\nnot found\n\n");
}
void create_queue()
{
    struct social_net *temp,*p;
     int n;
     printf("Enter no. of account :");
     scanf("%d",&n);
     for(int i=0;i<n;i++)
     {


    if (rear==NULL)
    {
        rear=(struct social_net*)malloc(sizeof(struct social_net)*1000);
        printf("..................................................................................\n");
        printf("\n \tEnter your Name:");
        scanf("\t\t%s",(rear->name));
        printf("\n \tEnter your age:");
        scanf("\t\t%d",&(rear->age));
        printf("\n \tEnter your Email ID:");
        scanf("\t\t%s",(rear->email));
        printf("\n \tEnter your Username:");
        scanf("\t\t%s",(rear->username));
        printf("\n \tEnter Password:");
        scanf("\t\t%s",(rear->password));
        printf("..................................................................................\n");
        rear->connect=NULL;
        front=rear;


    }

    else

    {
        temp=(struct social_net*)malloc(sizeof(struct social_net)*1000);
        printf("..................................................................................\n");
        printf("\n \tEnter your Name:");
        scanf("\t\t%s",(temp->name));
        printf("\n \tEnter your age:");
        scanf("\t\t%d",&(temp->age));
        printf("\n \tEnter your Email ID:");
        scanf("\t\t%s",(temp->email));
        printf("\n \tEnter your Username:");
        scanf("\t\t%s",(temp->username));
        printf("\n \tEnter Password:");
        scanf("\t\t%s",(temp->password));
        printf("..................................................................................\n");
        rear->connect=temp;
        rear=temp;
    }
     }
}
void display_queue()
{
    struct social_net *p;
    p=(struct social_net*)malloc(sizeof(struct social_net)*1000);

    if(front==NULL)
    {
        printf("\n No Account created yet\n");
    }
    else
    {    p=front;
        printf("\n \tName  \t\tAge  \t\tEmail ID  \t\tUsername \n\n");
        while(p!=NULL)
           {
            printf("\n\t%s\t\t%d\t\t%s\t\t%s",p->name,p->age,p->email,p->username);
            printf("\n");
            p=p->connect;
           }
    }
}
void del_queue()
{
    struct social_net *temp;
    if(front==NULL)
    {
        printf("\n*Queue Underflow*\n");
    }
    else
    {
    temp=front;
    front=front->connect;
    free(temp);
    }
}
void insert_queue ()
{
      struct social_net *temp,*p;
     int n;
     printf("Enter no. of account to enter at last :");
     scanf("%d",&n);
     for(int i=0;i<n;i++)
     {


    if (rear==NULL)
    {
        rear=(struct social_net*)malloc(sizeof(struct social_net)*1000);
        printf("Enter your Name:");
        scanf("%s",(rear->name));
        printf("Enter your age:");
        scanf("%d",&(rear->age));
        printf("Enter your Email ID:");
        scanf("%s",(rear->email));
        printf("Enter your Username:");
        scanf("%s",(rear->username));
        printf("Enter Password:");
        scanf("%s",(rear->password));
        rear->connect=NULL;
        front=rear;


    }

    else

    {
        temp=(struct social_net*)malloc(sizeof(struct social_net)*1000);
        printf("Enter your Name:");
        scanf("%s",(temp->name));
        printf("Enter your age:");
        scanf("%d",&(temp->age));
        printf("Enter your Email ID:");
        scanf("%s",(temp->email));
        printf("Enter your Username:");
        scanf("%s",(temp->username));
        printf("Enter Password:");
        scanf("%s",(temp->password));
        rear->connect=temp;
        rear=temp;
    }
     }
}
struct social_net *createt()
{
    struct social_net *p;
    int x;
    printf("Enter age (-1 to skip):");
    scanf("%d",&x);

    if(x==-1)
        return NULL;

    p=(struct social_net*)malloc(sizeof(struct social_net)*100);
    p->age=x;

    printf("Is anyone in your family Younger than %d of age ? (prevent repeatation .)\n",x);
    p->left=createt();

    printf("Is anyone in your family Older than %d of age ? (prevent repeatation .)\n",x);
    p->right=createt();

    return p;
}

void print2DUtil(struct social_net *root, int space)
{

    if (root == NULL)
        return;
    space+=COUNT;
    print2DUtil(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n\n", root->age);

    print2DUtil(root->left, space);
}

void print2D(struct social_net *root)
{
    print2DUtil(root, 0);
}



/*OUTPUT :




                                **************************************************
                                //////////////////////////////////////////////////
                                <<<<<<<<           HELLO !          >>>>>>>>
                                <<<<<<<<  WELCOME To The SMARTCOMM  >>>>>>>>
                                                - Your Best Social Networking Platform .
                                \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
                                *************************************************
..................................................................................
..................................................................................
Select :
1.Sign Up( Prime account ).
2.Display details( Prime account ).
3.Sort( only for Prime Account ).
4.Search ( only for Prime Account ).
5.Insert( Prime Account ).
6.Delete ( Prime Account ).
7. Modify ( only for Prime Account ).
8.Sign Up ( Regular User Account ).
9.Display details ( Regular User Account ).
10.Delete ( Regular User Account ).
11.Insert ( Regular User Account ).
12.Form Family age Tree .
12

 How much older are you ?
Enter age (-1 to skip):19
Is anyone in your family Younger than 19 of age ? (prevent repeatation .)
Enter age (-1 to skip):15
Is anyone in your family Younger than 15 of age ? (prevent repeatation .)
Enter age (-1 to skip):11
Is anyone in your family Younger than 11 of age ? (prevent repeatation .)
Enter age (-1 to skip):-1
Is anyone in your family Older than 11 of age ? (prevent repeatation .)
Enter age (-1 to skip):-1
Is anyone in your family Older than 15 of age ? (prevent repeatation .)
Enter age (-1 to skip):17
Is anyone in your family Younger than 17 of age ? (prevent repeatation .)
Enter age (-1 to skip):-1
Is anyone in your family Older than 17 of age ? (prevent repeatation .)
Enter age (-1 to skip):-1
Is anyone in your family Older than 19 of age ? (prevent repeatation .)
Enter age (-1 to skip):42
Is anyone in your family Younger than 42 of age ? (prevent repeatation .)
Enter age (-1 to skip):35
Is anyone in your family Younger than 35 of age ? (prevent repeatation .)
Enter age (-1 to skip):29
Is anyone in your family Younger than 29 of age ? (prevent repeatation .)
Enter age (-1 to skip):-1
Is anyone in your family Older than 29 of age ? (prevent repeatation .)
Enter age (-1 to skip):-1
Is anyone in your family Older than 35 of age ? (prevent repeatation .)
Enter age (-1 to skip):37
Is anyone in your family Younger than 37 of age ? (prevent repeatation .)
Enter age (-1 to skip):-1
Is anyone in your family Older than 37 of age ? (prevent repeatation .)
Enter age (-1 to skip):-1
Is anyone in your family Older than 42 of age ? (prevent repeatation .)
Enter age (-1 to skip):49
Is anyone in your family Younger than 49 of age ? (prevent repeatation .)
Enter age (-1 to skip):-1
Is anyone in your family Older than 49 of age ? (prevent repeatation .)
Enter age (-1 to skip):-1

                              49


               42


                                             37


                              35


                                             29


19


                              17


               15


                              11


Process returned 0 (0x0)   execution time : 92.586 s
Press any key to continue.*/
