#include<stdio.h>
void main()
{
 int a[10],i,n,sum=0,ave;
 printf("Enter the number: \n");
 scanf("%d",&n);
 printf("Enter the elements of array: ");

 for(i=0;i<n;i++)
 {
  printf("Enter number%d",i);
  scanf("%d",&a[i]);
  sum=sum+a[i];
  }
  ave=sum/n;
  printf("Average of numbers is %d",ave);
}
