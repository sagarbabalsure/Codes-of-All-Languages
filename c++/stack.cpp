#include<iostream>
#include<stack>
using namespace std;
void showstack(stack<int>s)
{
	while(!s.empty())
	{
		cout<<s.top()<<"\t";
		s.pop();

	}
}
int main()
{
	stack<int>s1;
	stack<int>s2;
	cout<<s1.size()<<endl;
	s1.push(2);
	s1.push(4);
	s1.push(6);
	s1.push(8);
	
	cout<<s1.top()<<endl;
	cout<<s1.size()<<endl;
	s1.pop();
	cout<<s1.top()<<endl;
	cout<<s1.size()<<endl;
	cout<<s1.empty()<<endl;
	s1.push(8);
	showstack(s1);
	cout<<"\n";
	s2.push(1);
	s2.push(3);
	s2.push(5);
	s2.push(7);
	showstack(s2);
	cout<<"\n";
	s1.swap(s2);
	showstack(s1);
	cout<<"\n";
	showstack(s2);
	cout<<"\n";

  return 0;
}