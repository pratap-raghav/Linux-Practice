#include <ctype.h>
#include <stdio.h>
#include <string.h>

void findFirst(char, int, int);

int cnt, n = 0;
char fSet[10][100];   
char prod[10][10];   
char first[10];       
int k;

int main()
{
	int jm = 0, i;
	char c;
	printf("Enter number of productions: ");
    	scanf("%d", &cnt);
	
	printf("Enter the productions (e.g., X=Yz):\n");
	for (int i = 0; i < cnt; i++) {
		printf("Production %d: ", i + 1);
		scanf("%s", prod[i]);
	}

	int kay;
	char done[cnt];
	int ptr = -1;

	for (k = 0; k < cnt; k++) {
	for (kay = 0; kay < 100; kay++) {
	    fSet[k][kay] = '!';
	}
	}

	int p1 = 0, p2, x;

	for (k = 0; k < cnt; k++) {
	c = prod[k][0];
	p2 = 0;
	x = 0;

	for (kay = 0; kay <= ptr; kay++)
	    if (c == done[kay])
		x = 1;

	if (x == 1)
	    continue;

	findFirst(c, 0, 0);
	ptr += 1;

	done[ptr] = c;
	printf("\n First(%c) = { ", c);
	fSet[p1][p2++] = c;

	for (i = 0 + jm; i < n; i++) {
	    int l = 0, chk = 0;

	    for (l = 0; l < p2; l++) {
		if (first[i] == fSet[p1][l]) {
		    chk = 1;
		    break;
		}
	    }
	    if (chk == 0) {
		printf("%c, ", first[i]);
		fSet[p1][p2++] = first[i];
	    }
	}
	printf("}\n");
	jm = n;
	p1++;
	}
}

void findFirst(char c, int q1, int q2)
{
    int j;

    if (!(isupper(c))) {
        first[n++] = c;
    }

    for (j = 0; j < cnt; j++) {
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

