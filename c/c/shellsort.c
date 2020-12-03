#include<stdio.h>
void shellsort();
void swap();
void main()
{
	int n,a[n],i,j;
	printf("How many elements in array: \n");
	scanf("%d",&n);
	printf("array elements before sorting: \n");
	for(i=0;i<n;i++)
	{
		printf("Enter elements %d\n",i+1);
		scanf("%d",&a[i]);
	}
	shellsort(a,n);
	printf("sorted array is: \n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
void shellsort(int a[],int n)
{
	int gap,i;
	int temp=gap;
	for(int gap=n/2;gap>0;gap/=2)
	{
      for(int i=0;temp<n;i++,temp++)
      {
      	if(a[i]>a[temp])
      	{
      	 swap(a[i],a[temp]);
      	}
      }
      for(i--,temp--;i>=0;--i,--temp)
      {
      	if(a[i]>a[temp])
      	{
      		swap(a[i],a[temp]);
      	}
      }
	}
}
void swap()
{
	int n,t,i,temp,a[n];
	t=a[i];
	a[i]=a[temp];
	a[temp]=t;
}
