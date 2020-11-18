#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i,j,x=0,y=0;
	string s1,s2;
	string s3="Benedict";
	string s4="Cumberbatch";
	cin>>s1>>s2;
	if(s1.length()>7 && s2.length()>7 && s1[0]=='B' && s2[0]=='C')
	{
		for(i=0;s1[i]!='\0';i++)
		{
			for(j=0;s3[j]!='\0';j++)
			{
				if(s1[i]==s3[j]){
					x++;
					break;
				}
			}
		}
		for(i=0;s2[i]!='\0';i++)
		{
			for(j=0;s4[j]!='\0';j++)
			{
				if(s2[i]==s4[j]){
					y++;
					break;
				}
			}
		}
	}
	if(x>3 && y>5){
		cout<< "It is him";
	}
	else{
		cout<< "It is someone else";
	}
	
	return 0;
}