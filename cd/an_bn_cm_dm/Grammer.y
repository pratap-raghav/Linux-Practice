%{
#include <stdio.h>
#include <stdlib.h>

int yyerror(char*); 
int yylex();  // Lexical analyzer

%}

%token A B C D NEWLINE

%%

stmt: S NEWLINE { printf("valid\n"); return 1; }  // Valid string, print valid
    ;

S: X Y ;  // Rule for the string: first X, then Y

X: A X B   // Rule for a^n b^n: matching a's and b's
  |         // Empty rule for the base case
    ;

Y: C Y D   // Rule for c^m d^m: matching c's and d's
  |         // Empty rule for the base case
    ;

%%

extern FILE *yyin;

void main() {
    printf("Enter a string: \n");
    do {
        yyparse();  // Parse the input string
    } while (!feof(yyin));  // Keep parsing until end of input
}

int yyerror(char* str) {
    printf("invalid\n");  // If there's a syntax error, print invalid
    return 1;
}
