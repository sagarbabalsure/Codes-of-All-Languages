#include<iostream>
#include <cstdlib>
using namespace std;
int n,i,j;
class tour
{
    
public:
int tour_number;
char tour_name[50];

float tour_price,tax,tour_discount;
string city;

    tour()
    {
    	
    }

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

	void show_tour()
	{
		
		cout<<endl<<tour_number<<"\t\t"<<tour_name<<"\t\t"<<tour_price<<"\t\t"<<tour_discount<<"\t\t"<<tax<<endl;
		
	}
	int gettour()
	{
		return tour_number;
	}
	float gettour_price()
	{
		return tour_price;
	}

	char* getName()
	{
		return tour_name;
	}

	float getDiscount()
	{
		return tour_discount;
	
    }
    
   void place_tour()
   {
	string city;
	cout<<"Enter the city where you want to go: ";
	cin>>city;
    
	 if(getName()==city)
	 {
	 	cout<<"\t\t*******record found*******"<<endl;
	 	cout<<"Tour number is: "<<tour_number<<endl;
	 	cout<<"Tour name is: "<<tour_name<<endl;
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

		cout<<"\n\nThank You...";

		 
	 }
	 else
	 {
	 	cout<<"record not found"<<endl;
	 }
	
   }

    
   
};


int main()
{
	tour t[100];
	
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
	cout<<"\n\nT.NO\t\tNAME\t\tPRICE\t\tDISCOUNT\tTAX"<<endl;
	for(i=0;i<n;i++)
	{
		t[i].show_tour();
	}
	cout<<"\n\n";
    
	for(i=0;i<n;i++)
	{
		
	t[i].place_tour();
    }


	
	return 0;

}