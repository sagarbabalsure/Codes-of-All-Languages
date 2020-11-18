#include<iostream>
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	//n=s1.length();
	for(int i=0;s1[i]!='\0';i++)
	{
		if(int(s1[i]) < int(s2[i]))
		{
			cout<<"-1";
		}
		else if(int(s1[i]) > int(s2[i]))
		{
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	/*string s1;
	cin>>s1;
	int x=s1[1];
	cout<<x<<" "<<int(s1[0]);*/
	return 0;
}