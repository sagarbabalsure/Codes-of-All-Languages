#include<iostream>
using namespace std;
int FirstOcc(int a[],int n,int x)
{
	int l=0,h=n-1;
	int r1=-1;
	while(l<=h){
	int mid=(l+h)/2;
	if(a[mid]==x){
		r1=mid;
		h=mid-1;
	}
	else if(a[mid]>x)
		 h=mid-1;
    else
    	 l=mid+1;
}
return r1;
}
int LastOcc(int a[],int n,int x)
{
	int l=0,h=n-1;
	int r2=-1;
	while(l<=h){
	int mid=(l+h)/2;
	if(a[mid]==x){
		r2=mid;
		l=mid+1;
	}
	else if(a[mid]>x)
		 h=mid-1;
    else
    	 l=mid+1;
}
return r2;
}
int FindCount(int a[],int n,int x)
{
	int first=FirstOcc(a,n,x);
	int last=LastOcc(a,n,x);
	return (last-first+1);
	
}
int main(){
	int a[10],n,count=0;
	int x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>x;
	cout<<FindCount(a,n,x);
}