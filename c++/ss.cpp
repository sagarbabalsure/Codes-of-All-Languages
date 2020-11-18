#include<iostream>
#include<fstream>
using namespace std;
/*int main()
{
	string name;
	fstream fp;
	fp.open("data",ios::out);
	fp<<"new file is created"<<endl;
	getline(cin,name);
	fp<<name;
	fp.close();
	fp.open("data",ios::in);
	while(!fp.eof())
	{
		getline(fp,name);
		cout<<name<<endl;
	}
    fp.close();

	return 0;
}*/
int main()
{
	string name;
	cin>>name;
	cout<<name<<endl;
	fstream fp;
	fp.open("data1",ios::out);
	fp<<name;
	fp.close();
	fp.open("data1",ios::in);
	fp>>name;
	return 0;

}