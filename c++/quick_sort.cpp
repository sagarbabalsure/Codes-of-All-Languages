#include<iostream>
using namespace std;
void Swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int low,int high)
{
	int pIndex=low;
	int pivot=a[high];
	for(int i=low;i<high;i++)
	{
		if(a[i]<pivot){
			Swap(&a[i],&a[pIndex]);
			pIndex++;
		}
	}
	Swap(&a[pIndex],&a[high]);
	return pIndex;
}
void QuickSort(int a[],int low,int high)
{
	if(low<high){
		int pi=partition(a,low,high);
		QuickSort(a,low,pi-1);
		QuickSort(a,pi+1,high);
	}
}


int main()
{
	int a[100],n;
	cin>>n;
	int low=0,high=n-1;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	QuickSort(a,low,high);
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
}