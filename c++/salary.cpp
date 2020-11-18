#include<iostream>
using namespace std;
int main()
{
	int T,a[100],i,j,temp;
	cin>>T;
	for(int t=0;t<T;t++)
	{
	 for(i=0;i<3;i++)
		cin>>a[i];

	 for( i = 0; i < 3; i++)
      {
        for(j = 0; j < (3-1-i); j++)
        {
            if(a[j] > a[j+1]) 
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    cout<<"case " <<t+1 <<":"<<a[1]<<endl;
}
    return 0;
}