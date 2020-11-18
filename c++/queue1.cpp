#include<iostream>
using namespace std;
#define MAX 10
int q[MAX],front=0,rear=0;

void enqueue(int x)
{
	if(rear==MAX){
		cout<<"queue is full"<<endl;
	}else{
		q[rear]=x;
		cout<<q[rear]<<endl;
		//++rear;
	}
}
void dequeue()
{
	int d;
	if(front==rear==-1){
		cout<<"queue is empty"<<endl;
	}else{
		d=q[front];
		front++;
	}
	cout<<d<<endl;
	cout<<q[front]<<endl;
}
int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	dequeue();

}