#include<iostream>
using namespace std;
template <class T>
class calci
{
public:
	T n1;
	T n2;
	calci(T p1 , T p2)
	{
		n1=p1;
		n2=p2;
	}
	void result()
	{
		cout<<"numbers are :"<<n1<<" and "<<n2<<endl;
		cout<<"addition :"<<add()<<endl;
		cout<<"substraction :"<<sub()<<endl;
		cout<<"multiplication :"<<mult()<<endl;
		cout<<"division :"<<div()<<endl;

	}
	T add(){
	return (n1+n2);
    }
	T sub(){
	return (n1-n2);
    }
	T mult(){
	return (n1*n2);
    }
	T div(){
	return (n1/n2);
    }

};
int main()
{
	int i1,i2;
	float f1,f2;
	cin>>i1>>i2;
	cin>>f1>>f2;
	calci<int>c1(i1,i2);
	calci<float>c2(f1,f2);
	c1.result();
	c2.result();
	return 0;

}