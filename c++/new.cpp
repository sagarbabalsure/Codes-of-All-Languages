#include<iostream>
using namespace std;
int sum()
{
	int *p=new int(34);
	int *q=new int(24);
	return (*p+*q);
}
int main()
{
	int *p=new int(12);
	int *q=new int(13);
	cout<<*p + *q<<endl;
	int *array=new int[5];
	for(int i=0;i<5;i++)
	{
		cin>>array[i];
	}
	for(int i=0;i<5;i++)
	{
	 cout<<array[i]<<endl;
    }
    delete p;
    delete q;
    cout<<sum();
	return 0;
}