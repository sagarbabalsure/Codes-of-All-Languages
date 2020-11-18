#include<iostream>
using namespace std;
int BinarySearch(int a[],int low,int high,int x)
{
	int result=0;
	if(low>high){
		return result;
	}
	int mid=(low+high)/2;
	if(a[mid]==x){
		result=mid;
		high=mid-1;
	}
	else if(a[mid]>x)
		 high=mid-1;
    else
    	 low=mid+1;

}
int main()
{
	int a[20],n;
	cin>>n;
	int x,low=0,high=n-1;
	cin>>x;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<BinarySearch(a,low,high,x);
	return 0;
}