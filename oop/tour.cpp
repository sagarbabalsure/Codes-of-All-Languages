#include<fstream>
//#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include <cstdlib>
using namespace std;
class tour1
{
    public:
int tour_number;
char tour_name[50];
};

class tour : public tour1
{

	float tour_price,tour_quantity,tax,tour_discount;

	public:

	void create_tour()
	{
		cout<<endl<<"Please Enter The tour Number: ";
		cin>>tour_number;
		cout<<endl<<"Please Enter The Name of The tour: ";
		cin.ignore();
		cin.getline(tour_name ,50);
		cout<<endl<<"Please Enter The Price of The tour: ";
		cin>>tour_price;
		cout<<endl<<"Please Enter The Discount (%): ";
		cin>>tour_discount;
	}

	void show_tour()
	{
		cout<<endl<<"tour #: "<<tour_number;
		cout<<endl<<"tour Name: "<<tour_name;
		cout<<endl<<"tour Price: "<<tour_price;
		cout<<endl<<"Discount : "<<tour_discount;
	}

	int gettour()
	{
		return tour_number;
	}
	float gettour(float a1)
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
};
fstream fp;
tour t;
void save_tour()
{
	fp.open("database.dat",ios::out|ios::app);
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

	fp.open("database.dat",ios::in);
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
	fp.open("database.dat",ios::in);
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

	fp.open("database.dat",ios::in|ios::out);
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
	fp.open("database.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
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
	remove("database.dat");
	rename("Temp.dat","database.dat");
	cout<<endl<<endl<<"\tRecord Deleted...";
	getchar();
}
void tour_menu()
{
	system("cls");
	fp.open("database.dat",ios::in);

	cout<<endl<<endl<<"\t\t tour MENU\n\n";

	cout<<"P.NO.\t\tNAME\t\tPRICE\n";

	while(fp.read((char*)&t,sizeof(tour)))
	{
		cout<<t.gettour()<<"\t\t"<<t.getName()<<"\t\t"<<t.gettour()<<endl;
	}
	fp.close();
}
void place_tour()
{
	int order_arr[50],quan[50],c=0;
	float amt,damt,total=0;
	char ch='Y';
	tour_menu();

	cout<<"\n PLACE YOUR TOUR";

	do{
		cout<<"\n\nEnter The tour #: ";
		cin>>order_arr[c];
		cout<<"\nQuantity: ";
		cin>>quan[c];
		c++;
		cout<<"\nDo You Want To Order Another tour ? (y/n)";
		cin>>ch;
		}while(ch=='y' ||ch=='Y');
	cout<<"\n\nThank You...";
	getchar();
	system("cls");
	cout<<"\n\n********************************FINAL BILL************************\n";
	cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
	for(int x=0;x<=c;x++)
	{
		fp.open("database.dat",ios::in);
		fp.read((char*)&t,sizeof(tour));
		while(!fp.eof())
		{
			if(t.gettour()==order_arr[x])
			{
				amt=t.gettour()*quan[x];
				damt=amt-(amt*t.getDiscount()/100);
				cout<<"\n"<<order_arr[x]<<"\t"<<t.getName()<<"\t"<<quan[x]<<"\t\t"<<t.gettour()<<"\t"<<amt<<"\t\t"<<damt;
				total+=damt;
			}
			fp.read((char*)&t,sizeof(tour));
		}
		fp.close();
	}
	cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
	getchar();
}
void admin_menu()
{
	system("cls");
	int option;
	cout<<"\n\tPress 1 to CREATE Tour";
	cout<<"\n\tPress 2 to DISPLAY ALL TOUR";
	cout<<"\n\tPress 3 to QUERY ";
	cout<<"\n\tPress 4 to MODIFY TOUR";
	cout<<"\n\tPress 5 to DELETE TOUR";
	cout<<"\n\tPress 6 to GO BACK TO MAIN MENU";
	cout<<"\n\n\tOption: ";
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
        case 6: system("cls");
				break;
                default:admin_menu();
	}
}
int main(int argc, char *argv[])
{
	system("cls");
	system("color 00");
	int option;

	for(;;)
	{
        cout<<"\n\t1. CUSTOMER";
		cout<<"\n\t2. ADMINISTRATOR";
		cout<<"\n\t3. EXIT";
        cout<<"\n\tOption: ";
		cin>>option;
        switch(option)
		{
			case 1: system("cls");
					place_tour();
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
