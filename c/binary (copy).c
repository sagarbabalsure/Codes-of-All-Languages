#include<stdio.h>
int main()
{
	int a[10];
	int i,n,h,m,j;
	int target;
	printf("how many elements: \n");
	scanf("%d",&n);
	printf("sorted array is :\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter target\n");
	scanf("%d",&target);
     h=n/2;
     if(target>=a[h])
     {
     	for(int j=h;j>=h;j++)
     	{
     		if(target == a[j]);
     		printf("position of target is %d\n",j);
     		break;
     	}
     }
     	else
     	{
     		for(int j=h-1;j<h;j--)
     		{
     			if(target == a[j]);
     			printf("position of target is %d\n",j);
     			break;
     		} 
        }
     	return 0;
}