#include<stdio.h>
int* largest(int*,int*);
int main()
{
	int a=12,b=23;
	int *l;
	l=largest(&a,&b); 
	printf("Largest is %d\n",*l);
}
int* largest(int *a,int *b )
{
	if(*a>*b)
		return a;
	else
		return b;
}