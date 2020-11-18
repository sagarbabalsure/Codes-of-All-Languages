#include<stdio.h>
void main()
{
 int num[10];
 int i=0;
 for(i=0; i<10; i++){
    printf("Enter number: ");
     scanf("%d",num[i]);
  }
  for(i=1; i<10; i++){
   if(num[i]%num[i-1]==0)
       printf("the number is not prime");
   else
       printf("number is prime");
   }
}
