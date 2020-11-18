#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	int n=s.length();
	int a[n]={ 0 };
	int i,j=0;
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]=='+'){
			j++;
		}
		else{
			a[j]=(s[i]-48);
		}
	}
	for(int i=0;i<=j;i++)
	{
		cout<<a[i]<<" ";
	}
	sort(a,a+5);
	cout<<endl;
	for(int i=0;i<=j;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<=j;i++)
	{
		cout<<a[i];
		if(i!=j)
			cout<<'+';
		else
			return ' ';
	}

	return 0;
}