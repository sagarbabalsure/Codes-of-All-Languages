#include<iostream>
using namespace std;
int main()
{
	int t,r,c,count=0,rcount=0,tcomp;
	cin>>t;
	int y=t,output[t];
	while(y!=0)
	{
		cin>>r>>c;
		int a[r][c];
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cin>>a[i][j];
			}
		}
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if(a[i][j] == 1)
				{
					count++; 
				}
			}
			if(count>rcount)
			{
				rcount = count;
				tcomp = i;
			}
			count=0;
		}
		if(rcount==0){
			output[y-1]=-1;
		}
		else{
			output[y-1]=tcomp;
		}y--,rcount=0;
	}
	for (int i = t-1; i >= 0; i--)
	{
		cout<<output[i]<<endl;
	}
	return 0;
}