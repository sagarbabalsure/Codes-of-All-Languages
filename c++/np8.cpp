#include<iostream>
using namespace std;

template <typename T>
class Test{
	T x, y;
public:
	Test(T t,T u):x(t),y(u){ }
	void display(){
		cout<<x<<" "<<y<<endl;
	}
};
int main()
{
	Test<int>t1(20,10);
	t1.display();
	Test<char>t2('a','b');
	t2.display();
	return 0;
}