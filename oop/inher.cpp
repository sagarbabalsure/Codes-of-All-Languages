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

	float tour_price,tax,tour_discount;

	public:

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
	}

	void show_tour()
	{
		
		cout<<endl<<tour_number<<"\t\t"<<tour_name<<"\t\t"<<tour_price<<"\t\t"<<tour_discount<<endl;
		
	}
};
int main()
{
	tour t[100];
	int n,i;
	cout<<"Enter no of tour records you want to add: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		t[i].create_tour();
	}
	cout<<"\n\nT.NO\t\tNAME\t\tPRICE\t\tDISCOUNT"<<endl;
	for(i=0;i<n;i++)
	{
		t[i].show_tour();
	}
	return 0;

}