#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>vec;
	for (int i = 1; i <= 5; i++)
	{
		/* code */vec.push_back(i);
	}
	vec.resize(3);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout<<" "<<vec[i];
	}
	cout<<"\n";
	vec.resize(4,10);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout<<" "<<vec[i];
	}
	cout<<"\n";
	vec.resize(5);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout<<" "<<vec[i];
	}
	return 0;
	
}