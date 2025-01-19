%{
#include <stdio.h>
%}

%%
[a-zA-Z]+   { printf("Input is an alphabet\n"); }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a string: ");
    yylex();
    return 0;
}
