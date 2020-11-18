#include<iostream>
#include <cstdlib>
using namespace std;

class tour
{
    
public:
int tour_number;
char tour_name[50];

float tour_price,tax,tour_discount;
string name,add,mobile_no,date;
int no_of_days;


	void create_tour()
	{
		cout<<endl<<"Enter The tour Number: ";
		cin>>tour_number;
		cout<<endl<<"Enter The Name of The tour: ";
		cin.ignore();
		cin.getline(tour_name ,50);
		cout<<endl<<"Enter The Price of The tour: ";
		cin>>tour_price;
		cout<<endl<<"Enter The Discount (%): ";
		cin>>tour_discount;
		cout<<endl<<"Enter The tax: ";
		cin>>tax;
	}

	
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
	void show_tour()
	{
		
		cout<<"Tour number is: "<<tour_number<<endl;
	 	cout<<"Tour name is: "<<tour_name<<endl;
	 	cout<<"Tour Price is: "<<tour_price<<endl;
	 	cout<<"Tour Discount is: "<<tour_discount<<endl;
	 	cout<<"Tour tax is: "<<tax<<endl;
		cout<<"Name of customer: "<<name<<endl;
		cout<<"address of customer: "<<add<<endl;
		cout<<"mobile number of customer: "<<mobile_no<<endl;
		cout<<"date: "<<date<<endl;
		cout<<"number of days: "<<no_of_days<<endl;

	}

	
    
 };


int main()
{
	tour t;
	
	//cout<<"\t\t******************************************"<<endl;
	cout<<"\t\t*******************************************"<<endl;
	cout<<"\t\t********TOUR MANAGEMENT SYSTEM*************"<<endl;
	cout<<"\t\t******************************************"<<endl;
	//cout<<"\t\t*******************************************"<<endl;

   cout<<"\n\n\t\t\t\t----------------WELCOME , TO OUR SYSTEM--------"<<endl;
   cout<<"\n\n";
	
	t.create_tour();
    t.customer_info();
    t.show_tour();

	
	return 0;

}