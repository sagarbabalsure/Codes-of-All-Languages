#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i=1;
	while(n)
	{
		if(n>i)
		{
			n=n-i;
			cout<<n<<" "<<i<<endl;
			if(n>2*i)
			{
				n=n-2*i;
				cout<<n<<" "<<i<<endl;
			}
			else
			{
				cout<<"Motu"<<endl;
				break;
			}
		}
		else
		{
			cout<<"Patlu"<<endl;
			break;
		}i++;
		cout<<i<<endl;
	}
}