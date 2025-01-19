#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main() {
    string operators[] = {
        "+", "-", "*", "/", "%",
        "++", "--",
        "==", "!=", ">", "<", ">=", "<=",
        "&&", "||", "!",
        "&", "|", "^", "~", "<<", ">>",
        "=", "+=", "-=", "*=", "/=", "%=", "<<=", ">>=", "&=", "^=", "|=",
        "&", "*", "?:", ","
    };
    string f;

    map<string, int> operatorCount;
    for (const string &op : operators) {
        operatorCount[op] = 0;
    }

    cout << "Enter File Name- ";
    cin >> f;
    ifstream file(f);
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string word;
    while (file >> word) {
        if (operatorCount.find(word) != operatorCount.end()) {
            operatorCount[word]++;
        }
    }

    file.close();

    cout << "Operator counts:" << endl;
    for (const auto &pair : operatorCount) {
        if (pair.second > 0) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }

    return 0;
}
