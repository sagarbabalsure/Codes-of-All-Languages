#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	string name;
	int roll_no;
	fstream fp;
	fp.open("data.txt",ios::out | ios::app);
	cin>>name>>roll_no;
	fp<<name<<roll_no;
	fp<<"Whatever i write here this will go into the file,so you have to understand the basic concept of the file pointer";
	fp.close();
	fp.open("data.txt",ios::in);
	while(fp){
	fp>>name>>roll_no;
	cout<<name<<" "<<roll_no;
	}
	
	fp.close();
	return 0;
}