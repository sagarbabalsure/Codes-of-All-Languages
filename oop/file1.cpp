#include<iostream>
#include<fstream>
using namespace std;
int main()
{
char data[100];
int r;
ofstream file;
file.open("xyz.txt");
cout<<"enter data into file"<<endl;
cout<<"enter student name"<<endl;
cin.ignore();
cin.getline(data,100);
file<<data<<endl;
cout<<"enter roll no"<<endl;
cin>>r;
file<<r<<endl;
file.close();
cin.ignore();
ifstream file1;
file1.open("xyz.txt");
//file1.seekg(,ios::beg);
file1>>data;
cout<<data<<endl;
file1>>r;
cout<<r<<endl;
file1.close();
return 0;
}
