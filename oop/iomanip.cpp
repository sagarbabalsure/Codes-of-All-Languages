#include<iostream>
#include <cstdlib>
#include<cstring>
using namespace std;

class tour
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
	char* get_city_name()
		{
			return city_name;
		}
	

	virtual void show_data()
	{
		//cout<<"Name of country: "<<country<<endl;
		//cout<<"Name of state: "<<state<<endl;
	 	cout<<"Name of city: "<<city_name<<endl;
	 	cout<<"Price of tour: "<<tour_price<<endl;
	 	cout<<"Discount for tour: "<<tour_discount<<"%"<<endl;
	 	cout<<"Tax for tour: "<<tax<<"%"<<endl;	
	 	
	
	}
};
class tour2:public tour
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
	
	void show_data()
	{
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
  
    string city;
   tour *ptr[10];
   tour2 t[10];
   /*for(int i=0;i<n;i++)
   {

   ptr[i]=&t[i];
   ptr[i]->create_tour();
  
   }
   for(int i=0;i<n;i++)
   {
   	t[i].customer_info();
    ptr[i]->show_data();
   }*/
  
 while(1)
 {
   cout<<"1.Add_Data"<<endl;
   cout<<"2.Book"<<endl;
   cout<<"3.Show_Data"<<endl;

   cout<<"Enter choice: ";
   int choice;
   cin>>choice;
   switch(choice)
   {
   	case 1:
   	 	  int n;
   	      cout<<"How many records you want to add: ";
   	      cin>>n;
   	      for(int i=0;i<n;i++)
		   {

		   ptr[i]=&t[i];
		   ptr[i]->create_tour();
		  
		   }
		   break;

    case 2:
   			
    		cout<<"Enter the city where you want to go: ";
    		
    	    cin>>city;
    		for(int i=0;i<n;i++)
    		{
    			for(int j=0;j<n;j++)
    			{
    			 if(t[j].city_name==city)
    			 {
    		 	  t[j].customer_info();
    		      break;
    		  	 }
    		  	 else{
    		  	 	cout<<"record not present"<<endl;
    		  	 }
    		    }break;
    		}
    		break;
    		
    case 3:
    		for(int i=0;i<n;i++)
			   {
			    ptr[i]->show_data();
			   }
			  break;

	default:
			cout<<"Error";

   }
}

	/*t.create_tour();
	cout<<"_______________________________________________________________________________"<<endl;
	t.customer_info();
	cout<<"_______________________________________________________________________________\n"<<endl;

	t.show_tour();*/

	return 0;

}