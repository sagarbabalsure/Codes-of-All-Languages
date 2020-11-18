	#include<iostream>
using namespace std;
void InsertionSort(int a[],int n)
{
	int temp;
	for (int i = 1; i < n; ++i)
	{
		for (int j = i; j>0 ; --j)
		{
			if(a[j]<a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int a[100],n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	InsertionSort(a,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
