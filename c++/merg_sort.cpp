#include<iostream>
using namespace std;
void Merge(int a[],int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for (i = 0; i < n1; i++)
	{
		L[i]=a[l+i];
	}
	for (j = 0; j < n2; j++)
	{
	 	R[j]=a[l+m+j];
	}
	i=0,j=0,k=1;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			a[k]=L[i];
			i++;
		}
		else{
			a[k]=R[j];
			j++;
		}
		k++;
	}

	while(i<n1){
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k]=R[j];
		j++;
		k++;
	}
}
void MergingSort(int a[],int l,int r)
{
	if(l<r){
	int mid=l+(r-l)/2;
	
	MergingSort(a,l,mid);
	MergingSort(a,mid+1,r);
	Merge(a,l,mid,r);
	}
}

int main()
{
	int a[100],n;
	cin>>n;
	//int start=0,end=n-1;

	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	MergingSort(a,0,n-1);
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
} 