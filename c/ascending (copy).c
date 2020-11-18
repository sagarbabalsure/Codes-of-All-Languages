#include<stdio.h>
void main()
{
 int a[10],i,n,j,x;
 printf("Enter no: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter elements %d",i);
  scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++)
  {
   for(j=i+1;j<n;j++)
   {
       if(a[i]>a[j])
       {
        x=a[i];
        a[i]=a[j];
        a[j]=x;
       }
   }
 }
 printf("The ascending order is: \n");
   for(i=0;i<n;i++)
   printf("%d\n",a[i]);
}
