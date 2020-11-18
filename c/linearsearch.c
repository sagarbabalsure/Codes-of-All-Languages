#include<stdio.h>
int main()
{
	int a[10];
	int target;
	int n,i;
	printf("How many elements in array: \n");
	scanf("%d",&n);
	printf("Enter the elements or array: \n");
	for ( i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the target: \n");
	scanf("%d",&target);
	 

    for (i = 0; i < n; i++)
  	{
  		if(a[i]==target)
  			{
  				printf("%d is present at location %d\n",target,i+1);
  				break;
  			}
  		
  	}
  	if(i==n)
  		printf("%d is not present in this array\n", target);
  	
  	return 0;

  }
