#include<iostream>
using namespace std;
int main()
{
	int T,n,A[100],p=1,i,j;
	cin>>T>>n;
   for(j=0;j<T;j++)
   {	
	for(i=0;i<n;i++)
	{
		cin>>A[i];
		p*=A[i];
	}
	cout<<p<<endl;
	p=1;
   }
	return 0;
}