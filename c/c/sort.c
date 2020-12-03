#include<stdio.h>
void mergesort(int a[],int n)
{
	if(n<2)
	{
		return;
	}
	int left=n/2;
	int right=(n-left);
	int L[left];
	int R[right];
	for (int i = 0; i < left; ++i)
	{
		L[i]=a[i];
	}
	for (int j = 0; j < right; ++j)
	{
		R[j]=a[j+left];
	}
	mergesort(L,left);
	mergesort(R,right);
	merge(a,L,R,left,right);
}
void merge(int a[],int L[],int R[],int left,int right)
{
	int i=0,j=0,k=0;
	while(i<left && j<right)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<left)
	{
		a[k]=L[i];
		i++;k++;
	}
	while(j<right)
	{
		a[k]=R[j];
		j++;k++;
	}
}
int main()
{
	int a[10],n,i;
	printf("Enter no. of elements in array: \n");
	scanf("%d",&n);
	printf("Enter array data: \n");
	for(i=0;i<n;i++)
	{
      scanf("%d",&a[i]);
	}
	mergesort(a,n);
	printf("sorted array IS: \n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}