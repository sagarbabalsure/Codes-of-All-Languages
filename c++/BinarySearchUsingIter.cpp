#include<iostream>
using namespace std;

int BinarySearch(int a[],int n,int key){
	int low=0,high=n-1;
	while(low<=high){
		int mid = low+(high-low)/2;
		if(key==a[mid]) return mid;
		else if(key<a[mid]) 
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

int main()
{
	int n;
	cout<<"Enter no of elements in array: ";
	cin>>n;
	int a[n],key;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Enter element to find: ";
	cin>>key;
	int result = BinarySearch(a,n,key);
	cout<<result<<endl;
}