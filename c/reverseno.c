#include<stdio.h>
int main()
{
	int n,reverse=0,r;
	printf("Enter the number: \n");
	scanf("%d",&n);
	while(n!=0)
	{
	 r=n%10;
	 reverse=reverse*10+r;
	 n/=10;
	 
	}
	printf("reverseno is %d\n",reverse );
	return 0;
}