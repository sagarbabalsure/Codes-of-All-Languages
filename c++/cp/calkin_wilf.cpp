#include<iostream>
using namespace std;
int main()
{
	int a=1,b=1;
	string s;
	cin>>s;
	for(int i=0;s[i]!='\0';i++)
	{
		if(s.length()==0)
		{
			cout<<a<<" "<<b<<endl;
		}
		else if(s[i] == 'L')
		{
			cout<<a<<" "<<a+b<<endl;
			a=a;
			b=a+b;
		}
		else if(s[i] == 'R')
		{
			cout<<a+b<<" "<<b<<endl;
			a=a+b;
			b=b;
		}
		else{
			cout<<"please enter valid input";
		}
	}
	return 0;
}