#include<stdio.h>
int linearsearch();
int main()
{
	int a[10],int target;
	int n;
	printf("How many elements in array: \n");
	scanf("%d",&n);
	printf("Enter the elements or array: \n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the target: \n");
	scanf("%d",&target);
	int linearsearch();
	
	return 0;
}
  int linearsearch()
  {
  	for (int i = 0; i < n; ++i)
  	{
  		if(a[i]==target)
  			return i;
  		else
  			return -1;
  	}
  }
