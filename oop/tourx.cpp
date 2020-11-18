#include<fstream>
//#include<conio.h>
#include<cstring>
#include<iomanip>
#include<iostream>
#include <cstdlib>
using namespace std;

void CLEAR() { std::cout << "\033[2J\033[1;1H"; }
class tour1
{
 public:
 	int no_of_days;
    char add[50],mobile_no[10];
    char date[20];
    char name[20];

    void customer_data()
  {
	cout<<"Enter your name: ";
	cin.ignore();
	cin.getline(name ,20);
	cout<<"Enter your address: ";
	cin.ignore();
	cin.getline(add ,50);
	cout<<"Enter your mobile number: ";
	cin.ignore();
	cin.getline(mobile_no ,10);
	cout<<"On which date you want to go to tour ?";
	cin>>date;
	cout<<"How many days you wany to stay there ?";
	cin>>no_of_days;

	cout<<"\n\nThank You...";
	getchar();
	CLEAR();
  }

  void show_bill()
	{
		cout<<"Name of CUSTOMER :"<<name<<"\n"<<endl;
		cout<<"address :"<<add<<"\n"<<endl;
		cout<<"mobile number :"<<mobile_no<<"\n"<<endl;
		cout<<"date on which you are going to tour :"<<date<<"\n"<<endl;
		cout<<"Number of days you stay there :"<<no_of_days<<"\n"<<endl;
	    getchar();
	}
	 char* get_cuctomer_name(){
	 return name;
	 }
	 char* get_add(){
	 return add;
	 }
	 char* get_mobileno(){
	 return mobile_no;
	 }
};


class tour : public tour1
{
public:

	int tour_number;
	char city_name[50];
	float tour_price,tax,tour_discount;
	

	void create_tour()
	{

		cout<<setw(31)<<endl<<"Enter The tour Number: ";
		cin>>tour_number;
		cout<<setw(29)<<endl<<"Enter The city Name: ";
		cin.ignore();
		cin.getline(city_name ,50);
		cout<<setw(37)<<endl<<"Enter The Price of The tour: ";
		cin>>tour_price;
		cout<<setw(32)<<endl<<"Enter The Discount (%): ";
		cin>>tour_discount;
	}

	void show_tour()
	{
		cout<<"\t"<<tour_number<<"\t\t"<<city_name<<"\t\t"<<tour_price<<"\t\t"<<setprecision(4)<<tour_discount;
		
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
float amt,damt,total=0;
int order_arr[50],quan[50],c=0;
void save_tour()
{
	fp.open("tour.txt",ios::out|ios::app);
	//t.Country();
    t.create_tour();
	fp.write((char*)&t,sizeof(tour));
	fp.close();
	cout<<endl<<endl<<"The tour Has Been Successfully Created...";
	getchar();
}
void show_all_tour()
{
CLEAR();
	cout<<endl<<"\t\tRECORDS."<<endl;
	cout<<"\tTourNumber\tTourName\tTourPrice\tDiscount"<<endl;
	fp.open("tour.txt",ios::in);
	while(fp.read((char*)&t,sizeof(tour)))
	{
		t.show_tour();
		cout<<"\n";
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
			CLEAR();
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
	CLEAR();
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
	CLEAR();
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
	CLEAR();
	fp.open("Documents/tour.txt",ios::in);

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

	getchar();

}

fstream fp1;
void bill()
{


    cout<<"\n\n********************************FINAL BILL************************\n";
    //fp1.open("record.txt",ios::in);
	//while(fp1.read((char*)&t,sizeof(tour)))
	//{
		t.show_bill();

		getchar();
	//}
	//fp1.close();
	cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
	for(int x=0;x<=c;x++)
	{
		fp.open("tour.txt",ios::in|ios::app);
		fp.read((char*)&t,sizeof(tour));
		while(!fp.eof())
		{
			if(t.gettour()==order_arr[x])
			{
				amt=t.gettour_price()*quan[x];
				damt=amt-(amt*t.getDiscount()/100);
				cout<<"\n"<<order_arr[x]<<"\t"<<t.getName()<<"\t"<<quan[x]<<"\t\t"<<t.gettour_price()<<"\t"<<amt<<"\t\t"<<damt;
				total+=damt;
				break;
			}
			fp.read((char*)&t,sizeof(tour));
		}
		fp.close();

	}
	cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;

}
void booking()
{
  fp1.open("record.txt",ios::out|ios::app);
    place_tour();
    t.customer_data();
    fp1.write((char*)&t,sizeof(tour));

	fp1.close();
	bill();
}

void booking_details()
{
	CLEAR();
	fp1.open("record.txt",ios::in);

	cout<<endl<<endl<<"********* booking details **********\n\n";

	cout<<"NAME\t\tADDRESS\t\tMOBILE\t\tCITYNAME\t\tPRICE"<<endl;

	while(fp1.read((char*)&t,sizeof(tour)))
	{
		cout<<t.get_cuctomer_name()<<"\t\t"<<t.get_add()<<"\t\t"<<t.get_mobileno()<<"\t\t"<<t.getName()<<"\t\t\t"<<t.gettour_price()<<endl;
	}
	fp1.close();
}

void admin_menu()
{
	CLEAR();
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
		case 1: CLEAR();
				save_tour();
				break;

		case 2: show_all_tour();
				break;

	    case 3:
				int num;
				CLEAR();
				cout<<"\n\n\tPlease Enter The tour Number: ";
				cin>>num;
				display_record(num);
				break;
        case 4: edit_tour();
		        break;

        case 5: delete_tour();
		        break;

		case 6: booking_details();
		        break;

        case 7: CLEAR();
				break;

        default:admin_menu();

	}
}
int main(int argc, char *argv[])
{
	CLEAR();
	system("color 00");
	int option;


	
               //cout<<"\t\t******************************************"<<endl;
        cout<<setw(80)<<"*******************************************"<<endl;
        cout<<setw(80)<<"********TOUR MANAGEMENT SYSTEM*************"<<endl;
        cout<<setw(80)<<"*******************************************"<<endl;
        //cout<<"\t\t*******************************************"<<endl;

       cout<<"\n\n"<<setw(120)<<setfill('-')<<"WELCOME , TO OUR SYSTEM--------------------------------------------------"<<endl;
       cout<<"\n\n";

	for(;;)
	{
        cout<<"\n\t1. CUSTOMER";
		cout<<"\n\t2. ADMINISTRATOR";
		cout<<"\n\t3. EXIT";
        cout<<"\n\tEnter Option: ";
		cin>>option;

        switch(option)
		{
			case 1: CLEAR();
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
