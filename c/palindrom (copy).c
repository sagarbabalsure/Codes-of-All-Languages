#include<stdio.h>
#include<string.h>
int main()
{
	char p[10],m[10],q[10];
	int i,l;
	printf("Enter the string: \n");
    scanf("%s",p);
	printf("string is %s \n",p );
	printf(" %d\n :",l=strlen(p));
	strcpy(q,p);
    strrev(q);
    printf("reverse string is %s\n",m );
    if(strcmp(p,q)==0)
    	printf("string is palindrom\n");
    else
    	printf("not\n");
    return 0;

   

}