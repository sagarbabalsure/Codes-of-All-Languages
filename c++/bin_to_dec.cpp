#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	int n,dec=0;
	cin>>n;
	string new_n = to_string(n);
	int t = new_n.size()-1;
	for (int i = 0; i < new_n.size(); ++i)
	{
		int x = (int)(new_n[i])-(int)(48);
		dec=dec+(x*pow(2,t));
		t--;
	}
	cout<<dec<<endl;
}