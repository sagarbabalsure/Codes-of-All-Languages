#include<stdio.h>
#define MAXSIZE 5
void insert();
int delete();
//void travers();
int queue[MAXSIZE];
int front=0;
int rare=0;
int n;
void main()
{
	
	insert(n);
	delete();
	//travers();
}
void insert(int n)
{
	if(MAXSIZE==rare)
	{
      printf("queue is full\n");
	}
	else
	{
	    printf("Enter the element: \n");
	    scanf("%d",&n);
		queue[rare]=n;
		rare++;
		insert(n);
	}
}
int delete()
{
	if(front==-1 && rare==-1)
	  printf("queue is empty\n");
	else
	{
		printf("deleted %d",queue[front]);
	    for(int i=1;i<rare;i++)
	    	queue[i-1]=queue[i];
	        rare--;
	}


}
