#include<stdio.h>
void add(int, int);
void sub(int, int);
void mux(int, int);
void div(int, int);
void main()
{
 int ch,a,b,c;
 printf("Enter two numbers: ");
 scanf("%d%d",&a,&b);
 printf("Enter ch: ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
        add(a,b);
        break;
 case 2:
        sub(a,b);
        break;
 case 3:
        mux(a,b);
        break;
 case 4:
        div(a,b);
        break;
 default:
        printf("wrong choice");
        break;
        }
}
void add(int a,int b)
{

     int c;
     c=a+b;
     printf("Addition is %d\n",c);
}
void sub(int a,int b)
{

     int c;
     c=a-b;
     printf("sub is %d\n",c);
}
void mux(int a,int b)
{

     int c;
     c=a*b;
     printf("multi is %d\n",c);
}
void div(int a,int b)
{

     int c;
     c=a/b;
     printf("division is %d\n",c);
}

