%{
#include <stdio.h> 
#include <stdlib.h> 
int res = 0; 
%}
%token number
%left '+' '-' 
%left '*' '/' 
%%
stmt: expr { res = $1; }
    ;
expr: expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { 
        if ($3 == 0) {
            printf("Division by zero error!\n"); 
            exit(1);
        } else {
            $$ = $1 / $3; 
        }
      }
    | number { $$ = $1; }
    ;
%%
void main() 
{
    printf("Enter an arithmetic expression:\n"); 
    yyparse(); 
    printf("Result = %d\n", res); 
    exit(0); 
}
void yyerror() 
{
    printf("Invalid expression\n"); 
    exit(1); 
}
