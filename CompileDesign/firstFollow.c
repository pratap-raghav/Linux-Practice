#include <ctype.h>
#include <stdio.h>
#include <string.h>

void followFirst(char, int, int);
void follow(char c);
void findFirst(char, int, int);

int cnt, n = 0;
char firstSet[10][100];
char followSet[10][100];
int m = 0;
char prod[10][10];
char f[10], first[10];
int k;
char ck;
int e;

int main()
{
	int jm = 0, km = 0, i;
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
			firstSet[k][kay] = '!';
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
		firstSet[p1][p2++] = c;

		for (i = 0 + jm; i < n; i++) {
			int l = 0, chk = 0;

			for (l = 0; l < p2; l++) {
				if (first[i] == firstSet[p1][l]) {
					chk = 1;
					break;
				}
			}

			if (chk == 0) {
				printf("%c, ", first[i]);
				firstSet[p1][p2++] = first[i];
			}
		}
		printf("}\n");
		jm = n;
		p1++;
	}
	printf("\n-----------------------------------------------\n\n");
	char doneFollow[cnt];
	ptr = -1;

	for (k = 0; k < cnt; k++) {
		for (kay = 0; kay < 100; kay++) {
			followSet[k][kay] = '!';
		}
	}

	p1 = 0;
	int land = 0;

	for (e = 0; e < cnt; e++) {
		ck = prod[e][0];
		p2 = 0;
		x = 0;

		for (kay = 0; kay <= ptr; kay++)
			if (ck == doneFollow[kay])
				x = 1;

		if (x == 1)
			continue;
		land += 1;

		follow(ck);
		ptr += 1;
		doneFollow[ptr] = ck;
		printf(" Follow(%c) = { ", ck);
		followSet[p1][p2++] = ck;

		for (i = 0 + km; i < m; i++) {
			int l = 0, chk = 0;

			for (l = 0; l < p2; l++) {
				if (f[i] == followSet[p1][l]) {
					chk = 1;
					break;
				}
			}
			if (chk == 0) {
				printf("%c, ", f[i]);
				followSet[p1][p2++] = f[i];
			}
		}
		printf(" }\n\n");
		km = m;
		p1++;
	}
}

void follow(char c)
{
	int i, j;

	if (prod[0][0] == c) {
		f[m++] = '$';
	}

	for (i = 0; i < 10; i++) {
		for (j = 2; j < 10; j++) {
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

void followFirst(char c, int c1, int c2)
{
	int k;

	if (!(isupper(c)))
		f[m++] = c;
	else {
		int i = 0, j = 1;

		for (i = 0; i < cnt; i++) {
			if (firstSet[i][0] == c)
				break;
		}

		while (firstSet[i][j] != '!') {
			if (firstSet[i][j] != '#') {
				f[m++] = firstSet[i][j];
			} else {
				if (prod[c1][c2] == '\0') {
					follow(prod[c1][0]);
				} else {
					followFirst(prod[c1][c2], c1, c2 + 1);
				}
			}
			j++;
		}
	}
}

