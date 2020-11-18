#include<stdio.h>
struct stationary
{
 char list[20];
 int price;
 int quantity;
 int receipt_no;
 }stationary[20];

void create();
void display();
/*void search();
void sort();
void modify();
void insert();*/
int n;

void main()
{
 int ch;
 printf("Enter your choice: ");
 scanf("%d",&ch);

 switch(ch)
 {
 	case 1:
 	       create();
 	       break;
 	case 2:
 	       display();
 	       break;

 }
}
void create()
{
	printf("Enter how many records you want to create: \n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	  printf("Enter list items: \n");
	  scanf("%s",stationary[i].list);
	  printf("Enter price of item: \n");
	  scanf("%d",&stationary[i].price);
	  printf("Enter quantity of that item: \n");
	  scanf("%d",&stationary[i].quantity);
	  printf("Enter receipt_no: \n");
	  scanf("%d",&stationary[i].receipt_no);
	}
	display();
}
void display()
{
	for(int i=0;i<n;i++)
	{
		printf("LIST: \n");
		printf("%s\n",stationary[i].list);
		printf("PRICE: \n");
		printf("%d\n",stationary[i].price);
		printf("QUANTITY: \n");
		printf("%d\n",stationary[i].quantity);
		printf("RECEIPT NUMBER: \n");
		printf("%d\n",stationary[i].receipt_no);
	}
	create();
}
