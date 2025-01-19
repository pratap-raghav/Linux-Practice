%{
#include <stdio.h>
#include <stdlib.h>
%}

%token A B

%%
stmt: S
    ;

S: A S B    // Recursive rule for a^n b^n
 |          // Empty string (epsilon production)
    ;

%%

void main() 
{
    printf("Enter a string:\n");
    yyparse();
    printf("Valid\n");
    exit(0);
}

void yyerror() 
{
    printf("Invalid\n");
    exit(1);
}
