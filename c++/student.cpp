#include<iostream>
using namespace std;
class student{
public:
	string name,add;
	int id,roll_no;

	void get(){
		cout<<"Enter student details: "<<endl;
		cin>>name>>add>>id>>roll_no;
	}
     void display(){
		cout<<"name of student is: "<<name<<endl;
		cout<<"address of student is: "<<add<<endl;
		cout<<"Id of student is: "<<id<<endl;
		cout<<"Roll no of student is: "<<roll_no<<endl;

	}
};
class Test:virtual public student{
public:
	int m1,m2;
	void getmarks(){
	cout<<"Enter marks: "<<endl;
	cin>>m1>>m2;
    }

};
class sports:virtual public student{
public:
	int sport_marks;
	void get_sports(){
		cout<<"Enter sports marks: "<<endl;
		cin>>sport_marks;
	}
};
class result:public Test,public sports{
public:
	float res;
	void get_result(){
		res=m1+m2+sport_marks;
	}
	void display_result(){
		cout<<"Result is: "<<res<<endl;
	}
};
int main()
{
	result r;
	r.get();
	r.getmarks();
	r.get_sports();
	r.get_result();
	r.display();
	r.display_result();
	cout<<r.res<<endl;
	return 0;
}