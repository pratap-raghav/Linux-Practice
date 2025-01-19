%{
#include<stdio.h>
%}

HOUR (0[0-9]|1[0-9]|2[0-3])
MINUTE (0[0-9]|[1-5][0-9])
SECOND (0[0-9]|[1-5][0-9])
TIME {HOUR}:{MINUTE}:{SECOND}

%%
{TIME}   { printf("Valid Time: %s\n", yytext); }
.        { /* ignore other characters */ }
%%

int yywrap() { return 1; }


int main()
{
    yylex();
    return 0;
}
