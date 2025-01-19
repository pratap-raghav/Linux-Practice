#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main() {
    string keywords[32] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"
    }, f;

    map<string, int> keywordCount;
    for (const string &keyword : keywords) {
        keywordCount[keyword] = 0;
    }	
    	cout<<"Enter File Name- ";
	cin>>f;
    ifstream file(f);
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string word;
    while (file >> word) {
        if (keywordCount.find(word) != keywordCount.end()) {
            keywordCount[word]++;
        }
    }

    file.close();

    cout << "Keyword counts:" << endl;
    for (const auto &pair : keywordCount) {
        if (pair.second > 0) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }

    return 0;
}
