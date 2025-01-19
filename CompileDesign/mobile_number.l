%{
#include<stdio.h>
%}

DIGIT [0-9]
MOBILE_NUMBER (5|6|7|8|9){1}{DIGIT}{9}

%%
{MOBILE_NUMBER}   { printf("Valid Mobile Number: %s\n", yytext); }
.                 {}
%%

int yywrap() { return 1; }


int main()
{
    yylex();
    return 0;
}
