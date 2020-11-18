#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,t,k,d,x=0;
	cin>>n>>t>>k>>d;
	int i=1,z,y;
	int m=n;
	while(m>0)
	{
		z=k*i;
		if(z!=n)
		{
		    y=t*i;
			if(d<y){
				m=m-2*k;
				x++;
			}
			else{
				m=m-k;
			}
		}
		else{
		  	m=m-k;
			x==-1;
		}
		++i;
	}
	if(x>0)
	{
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}	
	return 0;
}