#include<iostream>
using namespace std;
int BinarySearch(int a[],int low,int high,int x)
{
	int result=-1;
	if(low>high)
		return result;
	int mid=(low+high)/2;
	if(a[mid]==x){
		result=mid;
		BinarySearch(a,low,mid-1,x);
	}
	else if(a[mid]>x)
		return BinarySearch(a,low,mid-1,x);
    else
    	return BinarySearch(a,mid+1,high,x);

}
int main()
{
	int a[20],int n;
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