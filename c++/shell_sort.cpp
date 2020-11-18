#include<iostream>
using namespace std;
void ShellSort(int a[],int n)
{
	for(int gap=n/2;gap>0;gap=gap/2){
		for(int i=0,g=gap;i<gap,g<n;i++,g++){
			if(a[i]>a[g])
			{
				int temp=a[i];
				a[i]=a[g];
				a[g]=temp;
			}
		}
	}
}
int main()
{
	int a[100],n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	ShellSort(a,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
} 
