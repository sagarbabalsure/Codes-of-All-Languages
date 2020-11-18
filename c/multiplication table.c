#include<stdio.h>
void main()
{
 int n,i;
 int m;
 printf("Enter the number : ");
 scanf("%d",&n);
 printf("Table is: \n")
 for(int i=1;i<=10;i++)
 {
  m=n*i;
  printf("%d\n",m);
 }
}
