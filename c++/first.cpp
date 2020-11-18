#include<iostream>
using namespace std;
class employ
{
public:
	int id;
	string name;
	float salary;

	employ(int i,string n,float f)
	{
		this->id=i;
		this->name=n;
		this->salary=f;
	}
	void display()
	{
		cout<<id<<" "<<name<<" "<<salary<<endl;
	}
};
int main()
{
	employ e1=employ(12,"asd",12000);
	employ e2=employ(13,"qer",12578);
	e1.display();
	e2.display();
	return 0;
}