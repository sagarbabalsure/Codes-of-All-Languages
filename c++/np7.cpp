#include<iostream>
#include<exception>
using namespace std;

class S:public exception
{
public:
	const char * what() const throw(){
		return "It is specific exception";
	}
};
class M:public S
{
public:
	const char * what() const throw(){
		return "It is more specific exception";
	}
};
int main(int argc, char const *argv[])
{
	try{
		throw M();
	}
	catch (S& e){
		cout<<"clause 1: "<<e.what()<<endl;
	}
	catch (M& e){
		cout<<"clause 2: "<<e.what()<<endl;
	}
	catch (exception& e){
		cout<<"clause 3: "<<e.what()<<endl;
	}
	return 0;
}