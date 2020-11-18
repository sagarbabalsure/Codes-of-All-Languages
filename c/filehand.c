#include<stdio.h>
#include<string.h>

int main(){
	FILE *fp;
	FILE *fp1;
	char a[50];
	fp=fopen("demp.txt","r");
	if(fp==NULL){
		printf("File is unable to open\n");
	}else{
		fputs("Hi,I am sagar babalsure",fp);
	}
	printf("File is created and written in the file\n");

	if(fp==NULL){
		printf("FIle is unable to open\n");
	}else{
		while(fgets(a,50,fp)!=NULL){
			printf("%s\n",a);
		}
	}
	fclose(fp);
	return 0;
}