#include<iostream>
using namespace std;
void BubbleSort(int a[],int n)
{
	int temp;
	for (int i = 0; i < n; ++i)
	{
		int flag=0;
		for (int j = 0; j < n-i-1; ++j)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
}
int main()
{
	int a[10],n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Elements before sorting:  "<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	BubbleSort(a,n);
	cout<<"Elements after sorting:  "<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
}