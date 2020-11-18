#include<iostream>
#include<algorithm>
using namespace std;
int top=-1;
void push(int arr[],int n,int x)
{
	if(top==n+1){
		return;
	}else{
		top++;
		arr[top]=x;
	}
}
void pop(int arr[])
{
	if(top==-1)
	{
		return;
	}else{
		cout<<arr[top]<<" ";
		--top;
		pop(arr);
	}
}
int main()
{
	int t,n;
	cin>>t;
	while(t!=0){
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		//push(arr,n,arr[i]);
	}
	sort(arr,arr+n);
	for (int i = 0; i < n; ++i)
	{
		push(arr,n,arr[i]);
	}
	pop(arr);
	t--;
}
}