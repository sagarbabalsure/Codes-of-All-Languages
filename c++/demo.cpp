#include<iostream>
using namespace std;
int main()
{
	int a[3][3];
	a[1][2]=3;	
	a[0][2]=7;	
	a[2][2]=34;	
	a[1][1]=5;
	for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}	
	return 0;
}