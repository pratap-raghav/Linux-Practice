#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    string alphabets[52];
    int count[52] = {0};

    for (int i = 0; i < 26; i++) {
        alphabets[i] = 'a' + i;
        alphabets[i + 26] = 'A' + i;
    }

    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    ifstream file(filename.c_str());
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return 1;
    }

    string content;
    while (file >> content) {
        for (int i = 0; i < content.length(); i++) {
            for (int j = 0; j < 52; j++) {
                if (content[i] == alphabets[j][0]) {
                    count[j]++;
                }
            }
        }
    }

    file.close();

    for (int i = 0; i < 52; i++) {
    	if(count[i]!=0)
        	cout << alphabets[i] << " - " << count[i] << endl;
    }

    return 0;
}

