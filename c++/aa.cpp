#include<iostream>
#include<fstream>
using namespace std;
/*int main()
{
	fstream fp;
	string name;
	int roll_no,age;
	fp.open("data2",ios::out);
	cout<<"Enter name ,roll_no and age"<<endl;
    cin>>name>>roll_no>>age;
    fp<<name<<" "<<roll_no<<" "<<age;
    fp.close();
    cout<<"data written in file"<<endl;
    fp.open("data2",ios::in);
    fp>>name>>roll_no>>age;
    cout<<"\n";
    cout<<name<<"\t"<<roll_no<<"\t"<<age<<endl;
    fp.close();
	return 0;
}*/
int main()
{
	fstream fp;
	string name;
	int roll_no,age;
	fp.open("data2",ios::out);
	cin.get(name);
	cin.get(roll_no);
	cin.get(age);
	fp.put(name);
    fp.put(roll_no);
	fp.put(age);
	fp.close();
	fp.open("data2",ios::in);
	fp.get(name);
	fp.get(roll_no);
	fp.get(age);
    cout<<name<<"\t"<<roll_no<<"\t"<<age<<endl;
fp.close();
return 0;

}