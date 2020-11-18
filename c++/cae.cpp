#include<iostream>
using namespace std;
/*class B;
class A{
  private:
  	int a;
  public:
  	A(){a=5;}
  	void show(B&);

};
class B{
private:
int b;
public:
B(){b=6;}
friend void A::show(B& x);
};
void A::show(B& x){
	cout<<x.b<<endl;
}

int main()
{
A a;
B b;
a.show(b);
return 0;
}*/
class A{
public:
 virtual void show(){
 	cout<<"base class of A";
 }
 void print(){
 	cout<<"Base class";
 }
};
class B:public A{
public:
void show(){
	cout<<"derived class of A";
}
void print(){
	cout<<"Derived class";
}
};
int main()
{
	A *ptr;
	B b;
	ptr=&b;
	ptr->show();
	ptr->print();
	return 0;
}