#include<iostream>
using namespace std;

class base 
{
int x,y;
public:
	void putdata(){x=10; y=20;}
};
class derive:private base
{
public:
	int z;
	void putdata(){ base::putdata(); z=30;}
};
int main()
{
	derive d;
	d.putdata();
	int *p = &d.z;
	cout<< *p--<<endl;
	cout<< *p--<<endl;
	cout<< *p<<endl;

	return 0;
}