#include<iostream>
#include<list>
using namespace std;
void showlist(list<int>l)
{
	while(!l.empty())
	{
		cout<<l.front();
		l.pop_front();
	}
}
int main()
{
	list<int>l1={1,2,3,4};
	list<int>l2={11,22,33,44};
	cout<<l1.size()<<endl;
	cout<<l1.front()<<endl;
	l1.push_back(5);
	l1.push_front(6);
	showlist(l1);
	cout<<"\n";
	cout<<l1.size()<<endl;
	l1.pop_back();
	showlist(l1);
	cout<<"\n";
	list<int>::iterator i;
	i=l1.begin();
	l1.insert(i,8);
	l1.insert(i,2,9);
	showlist(l1);
	cout<<"\n";
	cout<<l1.size()<<endl;
	l1.reverse();
	showlist(l1);
	cout<<"\n";	
	l1.sort();
	showlist(l1);
	cout<<"\n";
	showlist(l2);
	cout<<"\n";
	l1.merge(l2);
	showlist(l1);
	cout<<"\n";

}