#include<iostream>
#include<array>
using namespace std;
int main()
{
	array<int,5>array1;
	array<int,5>array2;
	for(int i=0;i<5;i++)
	{
		cin>>array1[i];
	}
	for(int i=0;i<5;i++)
	{
		cin>>array2[i];
	}
	/*cout<<array1.at(2)<<endl;
	cout<<array1.at(4)<<endl;
	cout<<array1.front()<<endl;
    cout<<array1.back()<<endl;	
    cout<<array1[3]<<endl;
    cout<<array1.size()<<endl;
    cout<<array1.max_size()<<endl;
    cout<<array1.empty()<<endl; */
    for(int i=0;i<5;i++)
	{
		cout<<array1[i]<<"\t";
	}
	for(int i=0;i<5;i++)
	{
		cout<<array2[i]<<"\t";
	}
	array1.swap(array2);
	cout<<" after swapping"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<array1[i]<<"\t";
	}
	for(int i=0;i<5;i++)
	{
		cout<<array2[i]<<"\t";
	}
	for(int i=0;i<5;i++)
	{
		cout<<array1[i]+array2[i]<<"\t";
	}

    return 0;
}