#include<iostream>
using namespace std;
int main()
{
	long int attack,level,duration;
	cin>>attack>>level>>duration;
	cout<<(attack*duration) + (duration * (attack/level));
	return 0;
}