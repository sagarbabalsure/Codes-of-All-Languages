#include<iostream>
using namespace std;
class address
{
public:
	int hn;
	string colony;
	string city;
	address(int h,string c,string ct)
	{
		this->hn=h;
		this->colony=c;
		this->city=ct;
	}
	void disp1()
	{
		cout<<hn<<" "<<colony<<" "<<city<<endl;
	}
};
class student:public address
{
public:
	int id;
	string name;
	student(int i,string n,int h,string c,string ct):address(h,c,ct)
	{
		this->id=i;
		this->name=n;
	}
	void disp2()
	{
		cout<<id<<" "<<name<<endl;
	}

};

int main()
{
  student s1=student(12,"sag",2,"asdf","pune");
  s1.disp2();
  s1.disp1();
  return 0;
}