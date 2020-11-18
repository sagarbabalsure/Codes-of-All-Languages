#include<iostream>
using namespace std;

int BinarySearch(int a[],int low,int high,int key){
	if(low>high) return -1;
	int mid = low+(high-low)/2;
	if(key==a[mid]) return mid;
	else if(key>a[mid])
		return BinarySearch(a,mid+1,high,key);
	else
		return BinarySearch(a,low,mid-1,key);
}

int main()
{
	int n;
	cin>>n;
	int a[n],key;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int low=0,high=n-1;
	cout<<"Enter key: ";
	cin>>key;
	cout<<BinarySearch(a,low,high,key)<<endl;
	return 0;
}