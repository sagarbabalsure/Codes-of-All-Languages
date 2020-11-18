#include<iostream>
//#include<algorithm>
using namespace std;
int main()
{
	int N,i,j,c,d,temp,a[1000],count=0;
	cin>>N;
	for( i=0;i<N;i++)
		cin>>a[i];

	for( i = 0; i < N; i++)
      {
        for(j = 0; j < (N-1-i); j++)
        {
            if(a[j] > a[j+1]) 
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
   for(j=0;j<N;j++)
   {
  
    if(a[j]-a[j+1]==-1)
    {
      count++;
      j++;
    }
   }
   cout<<"-";
   cout<<a[j];
   return 0;

}