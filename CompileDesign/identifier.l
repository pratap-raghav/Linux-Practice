%{
#include<stdio.h>
%}

LETTER [a-zA-Z]
DIGIT [0-9]
IDENTIFIER {LETTER}({LETTER}|{DIGIT}|_)*

%%
{IDENTIFIER}   { printf("Valid Identifier: %s\n", yytext); }
.              { /* ignore other characters */ }
%%

int yywrap() { return 1; }


int main()
{
    yylex();
    return 0;
}
