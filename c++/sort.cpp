#include<iostream>
#include<algorithm>
//#include<array>
using namespace std;
int main(int argc, char const *argv[])
{
	/*array<int,6>array1={1,34,123,54,24,5};
	for(int i=0;i<6;i++)
	{
		cout<<array1[i]<<"\t";
	}
	cout<<"\n";
	array<int,6>::iterator i,j;
	i=array1.begin();
    j=array1.end();
	sort(i,j);
	for(int i=0;i<6;i++)
	{
		cout<<array1[i]<<"\t";
	}
	cout<<"\n";
	partial_sort(i,i+3,j);
	for(int i=0;i<6;i++)
	{
		cout<<array1[i]<<"\t";
	}
	cout<<"\n";
	cout<<is_sorted(i,j);*/
	int arr[]={1,23,2,87,34,22};
	for(int i=0;i<6;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
	sort(arr,arr+6);
	for(int i=0;i<6;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";


	return 0;
}