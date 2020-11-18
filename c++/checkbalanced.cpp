#include<iostream>
#include<string.h>
using namespace std;
#define MAX 10
int stack[MAX],top=-1;
void push(char c)
{
	if(top==max)
		cout<<"stack is full"<<endl;
	else{
		++top;
		stack[top]=c;
	}
}
void pop()
{
	if(top==-1){
		cout<<"stack is empty"<<endl;
	}else{
		--top;
	}
}
int CheckBalanced(string s)
{
	int count=0;
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]=="(" || s[i]=="{" || s[i]=="[")
		{
			push(s[i]);
			count++;
		}else if(s[i]==")" || s[i]=="}" || s[i]=="]")
		{
			if(top==-1){
				cout<<"Top does not pair"<<endl;
			}
			else{
				pop();
				count--;
			}
		}
	}
	return count;
}

int main()
{
	string s;
	cin>>s;
	int n=CheckBalanced(s);
	if(n==0){
		cout<<"string is balanced"<<endl;
	}else{
		cout<<"string is not balanced"<<endl;
	}
}