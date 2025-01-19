#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

void followFirst(char c, int prodIndex, int nextIndex);
void follow(char c);
void findFirst(char c, int prodIndex, int nextIndex);

int cnt, n = 0;
vector<string> firstSet(10, string(100, '!'));
vector<string> followSet(10, string(100, '!'));
vector<string> prod(10);
vector<char> f(10), first(10);
int m = 0;

int main() {
    cout << "Enter number of productions: ";
    cin >> cnt;

    cout << "Enter the productions (e.g., X=Yz):" << endl;
    for (int i = 0; i < cnt; i++) {
        cout << "Production " << (i + 1) << ": ";
        cin >> prod[i];
    }

    vector<char> done(cnt);
    int ptr = -1;

    for (int k = 0; k < cnt; k++) {
        char c = prod[k][0];
        int p2 = 0;
        bool alreadyDone = false;

        for (int kay = 0; kay <= ptr; kay++) {
            if (c == done[kay]) {
                alreadyDone = true;
                break;
            }
        }

        if (alreadyDone) continue;

        findFirst(c, 0, 0);
        done[++ptr] = c;
        cout << "\nFirst(" << c << ") = { ";
        firstSet[k][p2++] = c;

        for (int i = 0; i < n; i++) {
            if (strchr(firstSet[k].c_str(), first[i]) == nullptr) {
                cout << first[i] << ", ";
                firstSet[k][p2++] = first[i];
            }
        }
        cout << "}" << endl;
        n = 0; // Reset for the next production
    }

    cout << "\n-----------------------------------------------\n\n";
    vector<char> doneFollow(cnt);
    ptr = -1;

    for (int k = 0; k < cnt; k++) {
        followSet[k].assign(100, '!'); // Reset followSet
    }

    for (int e = 0; e < cnt; e++) {
        char ck = prod[e][0];
        int p2 = 0;
        bool alreadyDone = false;

        for (int kay = 0; kay <= ptr; kay++) {
            if (ck == doneFollow[kay]) {
                alreadyDone = true;
                break;
            }
        }

        if (alreadyDone) continue;

        follow(ck);
        doneFollow[++ptr] = ck;
        cout << "Follow(" << ck << ") = { ";
        followSet[e][p2++] = ck;

        for (int i = 0; i < m; i++) {
            if (strchr(followSet[e].c_str(), f[i]) == nullptr) {
                cout << f[i] << ", ";
                followSet[e][p2++] = f[i];
            }
        }
        cout << " }\n\n";
        m = 0; // Reset for the next production
    }

    return 0;
}

void follow(char c) {
    if (prod[0][0] == c) {
        f[m++] = '$';
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 2; j < 10; j++) {
            if (prod[i][j] == c) {
                if (prod[i][j + 1] != '\0') {
                    followFirst(prod[i][j + 1], i, (j + 2));
                }
                if (prod[i][j + 1] == '\0' && c != prod[i][0]) {
                    follow(prod[i][0]);
                }
            }
        }
    }
}

void findFirst(char c, int q1, int q2) {
    if (!isupper(c)) {
        first[n++] = c;
    }

    for (int j = 0; j < cnt; j++) {
        if (prod[j][0] == c) {
            if (prod[j][2] == '#') {
                if (prod[q1][q2] == '\0') {
                    first[n++] = '#';
                } else if (prod[q1][q2] != '\0' && (q1 != 0 || q2 != 0)) {
                    findFirst(prod[q1][q2], q1, (q2 + 1));
                } else {
                    first[n++] = '#';
                }
            } else if (!isupper(prod[j][2])) {
                first[n++] = prod[j][2];
            } else {
                findFirst(prod[j][2], j, 3);
            }
        }
    }
}

void followFirst(char c, int c1, int c2) {
    if (!isupper(c)) {
        f[m++] = c;
    } else {
        for (int i = 0; i < 10; i++) {
            if (firstSet[i][0] == c) {
                for (int j = 1; firstSet[i][j] != '!'; j++) {
                    if (firstSet[i][j] != '#') {
                        f[m++] = firstSet[i][j];
                    } else {
                        if (prod[c1][c2] == '\0') {
                            follow(prod[c1][0]);
                        } else {
                            followFirst(prod[c1][c2], c1, c2 + 1);
                        }
                    }
                }
                break;
            }
        }
    }
}
