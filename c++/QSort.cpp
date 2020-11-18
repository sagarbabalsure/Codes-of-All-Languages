#include<iostream>
using namespace std;

void Swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

int partition(int a[],int start,int end){
	int pivot = a[end];
	int pindex = start;
	for (int i = start; i < end; ++i)
	{
		if(a[i]<pivot){
			Swap(&a[i],&a[pindex]);
			pindex++;
		}
	}
	Swap(&a[pindex],&a[end]);
	return pindex;

}

void QuickSort(int a[],int start,int end){
	if(start<end){
		int pindex=partition(a,start,end);
		QuickSort(a,start,pindex-1);
		QuickSort(a,pindex+1,end);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[100];
	int start = 0,end=n-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	QuickSort(a,start,end);
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<""<<endl;
	return 0;
}
