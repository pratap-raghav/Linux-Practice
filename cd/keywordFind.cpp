#include<iostream>
using namespace std;

int main(){
	string array[32]={
	"auto",
	"break",
	"case",
	"char",
	"const",
	"continue",
	"default",
	"do",
	"double",
	"else",
	"enum",
	"extern",
	"float",
	"for",
	"goto",
	"if",
	"int",
	"long",
	"register",
	"return",
	"short",
	"signed",
	"sizeof",
	"static",
	"struct",
	"switch",
	"typedef",
	"union",
	"unsigned",
	"void",
	"volatile",
	"while"
	};
	
	string word; 
	int flag = 0;
	
	cout<<"Enter word- ";
	cin>>word;
	
	for(int i=0; i<32; i++){
		if (word.compare(array[i])==0){
			flag = 1;
		}
	}
	if(flag == 1)
		cout<<word<<" - Keyword";
	else
		cout<<word<<" - Not a keyword";
}
