%{
#include<stdio.h>
%}

DAY (0[1-9]|[12][0-9]|3[01])
MONTH (0[1-9]|1[0-2])
YEAR [0-9]{4}
DATE {DAY}/{MONTH}/{YEAR}

%%
{DATE}   { printf("Valid Date: %s\n", yytext); }
.        { /* ignore other characters */ }
%%

int yywrap() { return 1; }


int main()
{
    yylex();
    return 0;
}
