#include<iostream>
using namespace std;

int main(){
	string operators[] = {
        "+", "-", "*", "/", "%",
        "++", "--",
        "==", "!=", ">", "<", ">=", "<=",
        "&&", "||", "!",
        "&", "|", "^", "~", "<<", ">>",
        "=", "+=", "-=", "*=", "/=", "%=", "<<=", ">>=", "&=", "^=", "|=",
        "&", "*", "?:", ","
    };
	
	string word; 
	int flag = 0;
	
	cout<<"Enter symbol- ";
	cin>>word;
	
	for(int i=0; i<32; i++){
		if (word.compare(operators[i])==0){
			flag = 1;
		}
	}
	if(flag == 1)
		cout<<word<<" - Operator";
	else
		cout<<word<<" - Not an operator";
}
