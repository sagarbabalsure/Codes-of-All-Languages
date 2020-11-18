#include<iostream>
#include <cstdlib>
using namespace std;
class tour
{
public:
	string country;
	int n;
	tour()
	{
		cout<<"Enter the name of country: ";
		cin>>country;
		cout<<"\nEnter no of famous spots: ";
		cin>>n;
	}
};
class tour1
{
public:
	string state;
	int n1;
	tour1()
	{
		cout<<"Enter the name of state: ";
		cin>>state;
		cout<<"\nEnter no of famous spots: ";
		cin>>n1;

	}
};
class tour2: public tour,public tour1
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
		cout<<country<<"\t\t"<<state<<"\t\t"<<city_name<<"\t\t"<<tour_price<<"\t\t"<<tour_discount<<"%"<<"\t\t"<<tax<<"%"<<endl;	
	}
	void place_tour()
   {
	
	 	cout<<"Tour name is: "<<city_name<<endl;
	 	cout<<"Tour Price is: "<<tour_price<<endl;
	 	cout<<"Tour Discount is: "<<tour_discount<<endl;
	 	cout<<"Tour tax is: "<<tax<<endl;
	 	cout<<"\n\nCongratulations, You Successfully selected your tour, Please enter your Details."<<endl;
        cout<<"\n\n";
        string name,add,mobile_no,date;
		int no_of_days;
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

		cout<<"\n\nThank You...Your tour is Successfully booked";

		 
	 }
};


int main()
{
	
	tour2 t[100];
	int i=0,j=0,n;
	//cout<<"\t\t******************************************"<<endl;
	cout<<"\t\t*******************************************"<<endl;
	cout<<"\t\t********TOUR MANAGEMENT SYSTEM*************"<<endl;
	cout<<"\t\t******************************************"<<endl;
	//cout<<"\t\t*******************************************"<<endl;

   cout<<"\n\n\t\t\t\t----------------WELCOME , TO OUR SYSTEM--------"<<endl;
   cout<<"\n\n";
	cout<<"Enter no of tour records you want to add: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\n\tEnter the data of  "<<i+1<<" tour"<<endl;
		t[i].create_tour();
	}
	cout<<"\n\ncountry\t\tstate\t\tcity\t\tPRICE\t\tDISCOUNT\tTAX"<<endl;
	for(i=0;i<n;i++)
	{
		t[i].show_tour();
	}
	cout<<"\n\n";
	string city;
	cout<<"Enter the city where you want to go: ";
	cin>>city;
    
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		if(t[j].city_name==city)
    		{
    			cout<<"********record found********"<<endl;
    			t[j].place_tour();
    			break;
    		}
    		
    	}
    	break;
    	
    }
	return 0;

}