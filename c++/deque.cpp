#include<iostream>
#include<deque>
using namespace std;
void showd(deque<int>d)
{
	while(!d.empty())
	{
		cout<<d.back()<<"\t";
		d.pop_back();
	}
}
int main()
{
	int a[]={1,3,5,7};
	deque<int>d1(a,a+4);
	d1.push_back(9);
	d1.push_front(2);
	showd(d1);
	cout<<"\n";
	cout<<d1.size()<<endl;
	cout<<d1.max_size()<<endl;
	cout<<d1.front()<<endl;
	cout<<d1.back()<<endl;

	deque<int>::iterator i;
	i=d1.begin()+2;
	d1.insert(i,4);
	showd(d1);
	cout<<"\n";
	d1.insert(i,3,11);
	showd(d1);
	cout<<"\n";
	return 0;


}