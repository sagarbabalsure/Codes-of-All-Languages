#include<iostream>
using namespace std;

int variation(int a[],int n,int k)
{
	int count=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if(abs(a[i]-a[j])>=k) ++count;
		}
	}
	return count;
}

int main()
{
	int n,k; cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; ++i)
	 {
		cin >> a[i];
	 } 
	cout << variation(a,n,k) << endl;
	return 0;
}