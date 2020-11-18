#include<iostream>
using namespace std;
#define MAX 10
int stack[MAX],x,top=-1;

void push(int x)
{
	if(top==MAX){
		cout<<"Stach is full"<<endl;
	}
	else{
		++top;
		stack[top]=x;
	}
	//cout<<x<<endl;
	cout<<stack[top]<<endl;
}
void pop()
{
	int d;
	if(top==-1){
		cout<<"stack is empty"<<endl;
	}
	else{
		d=stack[top--];
	}
	cout<<d<<endl;
	cout<<stack[top]<<endl;
}
int main()
{
	push(5);
	push(29);
	push(34);
	pop();

}