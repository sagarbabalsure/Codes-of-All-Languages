#include<iostream>
using namespace std;
int main()
{
	int l,n,w,h;
	cin>>l;
	cin>>n;
	string str[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>w>>h;
		if(w<l or h<l){
			str[i]="UPLOAD ANOTHER";
		}
		else{
			if(w==h){
				str[i]="ACCEPTED";
			}
			else{
				str[i]="CROP IT";
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<str[i]<<endl;
	}
		
	return 0;
}