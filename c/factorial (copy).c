#include<stdio.h>
void main()
{
 int n,fact=1;
 printf("Enter the number: ");
 scanf("%d",&n);

  if(n<0)
  printf("error");
  else
  {
    for(int i=1;i<=n;i++)
  {
   fact=fact*i;
  }
  printf("factorial is %d",fact);
   }
}
