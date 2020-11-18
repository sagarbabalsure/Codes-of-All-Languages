#include<iostream>
#include <cstdlib>
using namespace std;
class tour1
{
public:
	string country;
	string state;
	void Country()
	{
		cout<<"Enter the name of country: ";
		cin>>country;
		cout<<"\n";
		cout<<"Enter the name of state: ";
		cin>>state;
		
	}
};
class tour2
{
public:
	string name,add,mobile_no,date;
    int no_of_days;
	
	void customer_info()
	{

        cout<<"\n\tPlease Enter your details....\n\n"<<endl;

		cout<<"Enter your name: "<<endl;
		cin>>name;
		cout<<"Enter your address: "<<endl;
		cin>>add;
		cout<<"Enter your mobile number: "<<endl;
		cin>>mobile_no;
		cout<<"On which date you want to go to tour ?"<<endl;
		cin>>date;
		cout<<"How many dats you wany to stay there ?"<<endl;
		cin>>no_of_days;

		cout<<"\t\t\n\nThank You..."<<endl;
		cout<<"\n\n\tCongratulations , Your tour is Successfully booked.Enjoy your tour.\n"<<endl;

	}

};
class tour: public tour1,public tour2
{
public:
	char city_name[50];
	float tour_price,tax,tour_discount;
	



	void create_tour()
	{
		
		cout<<endl<<"Enter The Name of The city: ";
		cin.ignore();
		cin.getline(city_name ,50);
		cout<<endl<<"Enter The Price of The tour: ";
		cin>>tour_price;
		cout<<endl<<"Enter The Discount (%): ";
		cin>>tour_discount;
		cout<<endl<<"Enter tax: ";
		cin>>tax;
	}
	
	void show_tour()
	{
		cout<<"Name of country: "<<country<<endl;
		cout<<"Name of state: "<<state<<endl;
	 	cout<<"Name of city: "<<city_name<<endl;
	 	cout<<"Price of tour: "<<tour_price<<endl;
	 	cout<<"Discount for tour: "<<tour_discount<<"%"<<endl;
	 	cout<<"Tax for tour: "<<tax<<"%"<<endl;	
	 	cout<<"Name of customer: "<<name<<endl;
		cout<<"address of customer: "<<add<<endl;
		cout<<"mobile number of customer: "<<mobile_no<<endl;
		cout<<"Date: "<<date<<endl;
		cout<<"Number of days: "<<no_of_days<<endl;
	
	}
};


int main()
{
	//cout<<"\t\t******************************************"<<endl;
	cout<<"\t\t*******************************************"<<endl;
	cout<<"\t\t********TOUR MANAGEMENT SYSTEM*************"<<endl;
	cout<<"\t\t******************************************"<<endl;
	//cout<<"\t\t*******************************************"<<endl;

   cout<<"\n\n\t\t\t\t----------------WELCOME , TO OUR SYSTEM--------"<<endl;
   cout<<"\n\n";
	tour t;
	t.Country();

	t.create_tour();
	cout<<"_______________________________________________________________________________"<<endl;
	t.customer_info();
	cout<<"_______________________________________________________________________________\n"<<endl;

	t.show_tour();
	return 0;

}