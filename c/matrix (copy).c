#include<stdio.h>
void main()
{
 int a[10][10],trans[10][10],sum[10][10];
 int i,j,r,c;
 printf("Enter the number of rows and column: ");
 scanf("%d%d",&r,&c);
 for(int i=0;i<r;i++)
 {
  for(int j=0;j<c;j++)
   {
    printf("Enter elements %d%d\n",i,j);
    scanf("%d",&a[i][j]);
   }
  }
   printf("matrix is: \n");
   for(int i=0;i<r;i++)
   {
    for(int j=0;j<c;j++)
    {
     printf("%d\t",a[i][j]);
     if(j==c-1)
        printf("\n\n");
     }
    }
    for(i=0;i<r;i++)
    {
     for(j=0;j<c;j++)
     {
         trans[j][i]=a[i][j];
     }
    }
    printf("The transpose of matrix: \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",trans[i][j]);
            if(j==r-1)
                printf("\n\n");
        }

    }

}
