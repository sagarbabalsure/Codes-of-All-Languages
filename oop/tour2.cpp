#include<fstream>
//#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include <cstdlib>
using namespace std;
class Country
{
public:
	string country;
	Country()
	{
		//cout<<"\t\t******************************************"<<endl;
	cout<<"\t\t*******************************************"<<endl;
	cout<<"\t\t********TOUR MANAGEMENT SYSTEM*************"<<endl;
	cout<<"\t\t******************************************"<<endl;
	//cout<<"\t\t*******************************************"<<endl;

   cout<<"\n\n\t\t\t\t----------------WELCOME , TO OUR SYSTEM--------"<<endl;
   cout<<"\n\n";
		cout<<"Enter the name of country: ";
		cin>>country;
		cout<<"\n";
		
	}
};
class State
{
public:
	string state;
	State()
	{
		cout<<"Enter the name of state: ";
		cin>>state;
	
	}
};

class tour : public Country,public State
{
public:

	int tour_number;
	char city_name[50];
	float tour_price,tax,tour_discount;

	public:

	void create_tour()
	{
		cout<<endl<<"Enter The tour Number: ";
		cin>>tour_number;
		cout<<endl<<"Enter The city Name: ";
		cin.ignore();
		cin.getline(city_name ,50);
		cout<<endl<<"Enter The Price of The tour: ";
		cin>>tour_price;
		cout<<endl<<"Enter The Discount (%): ";
		cin>>tour_discount;
	}

	void show_tour()
	{
		cout<<endl<<"tour number: "<<tour_number;
		cout<<endl<<"tour Name: "<<city_name;
		cout<<endl<<"tour Price: "<<tour_price;
		cout<<endl<<"Discount : "<<tour_discount;
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
		return city_name;
	}

	float getDiscount()
	{
		return tour_discount;
	}
};
fstream fp;
tour t;
int no_of_days;
float amt,damt,total=0;
int order_arr[50],quan[50],c=0;
string add,mobile_no,date;
char name[20];
void save_tour()
{
	fp.open("tour.txt",ios::out|ios::app);
    t.create_tour();
	fp.write((char*)&t,sizeof(tour));
	fp.close();
	cout<<endl<<endl<<"The tour Has Been Sucessfully Created...";
	getchar();
}
void show_all_tour()
{
	system("cls");

	cout<<endl<<"\t\tRECORDS.";

	fp.open("tour.txt",ios::in);
	while(fp.read((char*)&t,sizeof(tour)))
	{
		t.show_tour();

		getchar();
	}
	fp.close();
}
void display_record(int num)
{
	bool found=false;
	fp.open("tour.txt",ios::in);
	while(fp.read((char*)&t,sizeof(tour)))
	{
		if(t.gettour()==num)
		{
			system("cls");
			t.show_tour();
			found=true;
		}
	}

	fp.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();
}
void edit_tour()
{
	int num;
	bool found=false;
	system("cls");
	cout<<endl<<endl<<"\tPlease Enter The tour : ";
	cin>>num;

	fp.open("tour.txt",ios::in|ios::out);
	while(fp.read((char*)&t,sizeof(tour)) && found==false)
	{
		if(t.gettour()==num)
		{
			t.show_tour();
			cout<<"\nPlease Enter The New Details of tour: "<<endl;
			t.create_tour();
			int pos=1*sizeof(t);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&t,sizeof(tour));
			cout<<endl<<endl<<"\t Record Successfully Updated...";
			found=true;
		}
	}
	fp.close();
	if(found==false)
		cout<<endl<<endl<<"Record Not Found...";
	getchar();
}


void delete_tour()
{
	int num;
	system("cls");
	cout<<endl<<endl<<"Please Enter The tour #: ";
	cin>>num;
	fp.open("tour.txt",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.txt",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&t,sizeof(tour)))
	{
		if(t.gettour()!=num)
		{
			fp2.write((char*)&t,sizeof(tour));
		}
	}
	fp2.close();
	fp.close();
	remove("tour.txt");
	rename("Temp.txt","tour.txt");
	cout<<endl<<endl<<"\tRecord Deleted...";
	getchar();
}
void tour_menu()
{
	system("cls");
	fp.open("tour.txt",ios::in);

	cout<<endl<<endl<<"********* TOUR MENU **********\n\n";

	cout<<"T.NO\t\tNAME\t\tPRICE\t\tDISCOUNT"<<endl;

	while(fp.read((char*)&t,sizeof(tour)))
	{
		cout<<t.gettour()<<"\t\t"<<t.getName()<<"\t\t"<<t.gettour_price()<<"\t\t"<<t.getDiscount()<<endl;
	}
	fp.close();
}
void place_tour()
{
	
	char ch='Y';
	tour_menu();

	cout<<"\nPLEASE SELECT YOUR TOUR FROM THE ABOVE MENU.....";

	do{
		cout<<"\n\nEnter the tour number: ";
		cin>>order_arr[c];
		cout<<"\nEnter no of people want to go: ";
		cin>>quan[c];
		c++;

		cout<<"\nDo You Want To Order Another tour ? (y/n): ";
		cin>>ch;
		}while(ch=='y' ||ch=='Y');

	cout<<"\n\nCongratulations, You Successfully selected your tour, Please enter your Details."<<endl;
    cout<<"\n\n";

	cout<<"Enter your name: "<<endl;
	cin.ignore();
	cin.getline(name ,20);
	cout<<"Enter your address: "<<endl;
	cin>>add;
	cout<<"Enter your mobile number: "<<endl;
	cin>>mobile_no;
	cout<<"On which date you want to go to tour ?"<<endl;
	cin>>date;
	cout<<"How many days you wany to stay there ?"<<endl;
	cin>>no_of_days;

	cout<<"\n\nThank You...";
	getchar();
	system("cls");

	
}
char* customer_name()
{
	return name;
}
fstream fp1;
void show_bill()
{
	cout<<"Name of CUSTOMER :"<<name<<"\n"<<endl;
	cout<<"address :"<<add<<"\n"<<endl;
	cout<<"mobile number :"<<mobile_no<<"\n"<<endl;
	cout<<"date on which you are going to tour :"<<date<<"\n"<<endl;
	cout<<"Number of days you stay there :"<<no_of_days<<"\n"<<endl;

	cout<<"\nT.No\tCityName\tQuantity\tPrice \tAmount \tdamt\n";
	for(int x=0;x<=c;x++)
	{
		fp.open("tour.txt",ios::in);
		fp.read((char*)&t,sizeof(tour));
		while(!fp.eof())
		{
			if(t.gettour()==order_arr[x])
			{
				amt=t.gettour_price()*quan[x];
				damt=amt-(amt*t.getDiscount()/100);
				cout<<"\n"<<order_arr[x]<<"\t"<<t.getName()<<"\t \t"<<quan[x]<<"\t\t"<<t.gettour_price()<<"\t"<<amt<<"\t"<<damt;
				total+=damt;
			}
			fp.read((char*)&t,sizeof(tour));
		}
		fp.close();
	}
	cout<<"\n\n\t\t\t\t\tTOTAL AMOUNT  = "<<total;
	getchar();
}

void booking()
{
  fp1.open("record.txt",ios::out|ios::app);
  fp1.write((char*)&t,sizeof(tour));
    place_tour();
	fp1.close();
}
void show_records()
{
	fp1.open("record.txt",ios::in);
	fp1.read((char*)&t,sizeof(tour));
	show_bill();
	fp1.close();
}
void admin_menu()
{
	system("cls");
	int option;
	cout<<"\n\t1. CREATE TOUR DATA";
	cout<<"\n\t2. DISPLAY ALL TOURS";
	cout<<"\n\t3. QUERY ";
	cout<<"\n\t4. MODIFY TOUR";
	cout<<"\n\t5. DELETE TOUR";
	cout<<"\n\t6. Show booking Details";
	cout<<"\n\t7. GO BACK TO MAIN MENU";
	cout<<"\n\n\tEnter Option: ";
	cin>>option;
	switch(option)
	{
		case 1: system("cls");
				save_tour();
				break;

		case 2: show_all_tour();
				break;

	    case 3:
				int num;
				system("cls");
				cout<<"\n\n\tPlease Enter The tour Number: ";
				cin>>num;
				display_record(num);
				break;
        case 4: edit_tour();
		        break;

        case 5: delete_tour();
		        break;

		case 6: show_records();
		        break;

        case 7: system("cls");
				break;

        default:admin_menu();

	}
}
int main(int argc, char *argv[])
{
	system("cls");
	system("color 00");
	int option;


	//cout<<"\t\t******************************************"<<endl;
	cout<<"\t\t*******************************************"<<endl;
	cout<<"\t\t********TOUR MANAGEMENT SYSTEM*************"<<endl;
	cout<<"\t\t******************************************"<<endl;
	//cout<<"\t\t*******************************************"<<endl;


	for(;;)
	{
        cout<<"\n\t1. CUSTOMER";
		cout<<"\n\t2. ADMINISTRATOR";
		cout<<"\n\t3. EXIT";
        cout<<"\n\tEnter Option: ";
		cin>>option;

        switch(option)
		{
			case 1: system("cls");
					booking();
					getchar();
					break;

            case 2: admin_menu();
					break;

			case 3:
					cout<<"\n\tGood Bye!";
					exit(0);

            default :cout<<"Invalid Input...\n";
		}
	}
};
