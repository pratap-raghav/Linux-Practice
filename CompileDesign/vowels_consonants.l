%{
#include<stdio.h>
%}

%{
int vowels = 0, consonants = 0;
%}

%%
[aAeEiIoOuU]     { vowels++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]   { consonants++; }
.    {}
%%

int yywrap() { return 1; }


int main() {
    yylex();
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    return 0;
}
