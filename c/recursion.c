#include<stdio.h>
int fact(int);
void main()
{
 int n,factorial;
 printf("Enter the number: ");
 scanf("%d",&n);
 factorial=fact(n);
 printf("factorial is %d",factorial);
 }
 int fact(m)
 {
  if(m==0)
  return(1);
  else
  return(m*fact(m-1));
  }
