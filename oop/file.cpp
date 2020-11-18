#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int r;
	string name,cls,add;
	fstream fp;
	fp.open("data.txt",ios::in | ios::app);
	cin>>r>>name>>cls>>add;
	fp<<r<<name<<cls<<add;
	fp>>r>>name>>cls>>add;
	cout<<r<<" "<<name<<" "<<cls<<" "<<add;
	fp.close();
	return 0;
}