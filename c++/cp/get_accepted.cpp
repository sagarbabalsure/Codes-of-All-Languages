#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	getline(cin,s);
	//cout<<s;
	if(s == "Do you want to get accepted?"){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	return 0;
}