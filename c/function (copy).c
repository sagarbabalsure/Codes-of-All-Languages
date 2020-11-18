#include<stdio.h>
void add();
void substract();
void multiply();
void division();
void main()
{
 add();
 substract();
 multiply();
 division();
 }
 void add()
 {
  int a,b,c;
  printf("Enter the values");
  scanf("%d%d",&a,&b);
  c=a+b;
  printf("addition is %d",c);
  }
  void substract()
 {
  int a,b,c;
  printf("Enter the values");
  scanf("%d%d",&a,&b);
  c=a-b;
  printf("sub is %d",c);
  }
  void multiply()
  {
    int a,b,c;
    printf("Enter the values\n");
    scanf("%d%d",&a,&b);
    c=a*b;
    printf("multi is %d",c);
  }
  void division()
  {
    int a,b,c;
    printf("Enter the values\n");
    scanf("%d%d",&a,&b);
    c=a/b;
    printf("division is %d",c);
  }


