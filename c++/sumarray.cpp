#include<iostream>
using namespace std;

void sumArray(int A[],int N,int sum)
{
	for(int j=0;j<N;j++)
	{
	 for(int i=0;i<N;i++)
	 {
      sum=sum+A[i];
	 }
	 sum=sum-A[j];
	 cout<<sum<<"\t";
	 sum=0;
	}	
	 cout<<"\n";
}

int main()
{
	int T,N,A[100],sum=0;
	cin>>T>>N;
	for(int i=0;i<T;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>A[j];
		}
		sumArray(A,N,sum);

    }
	return 0;
}