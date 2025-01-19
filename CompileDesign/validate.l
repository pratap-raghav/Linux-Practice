%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

// Valid mobile number: (10 digits, optional country code)
[+][0-9]{1,3}[ ]?[0-9]{10}                { printf("Valid Mobile Number: %s\n", yytext); }
[0-9]{10}                                 { printf("Valid Mobile Number: %s\n", yytext); }

// Valid URL: Simple regex for demonstration purposes
(http|https)://[a-zA-Z0-9./?&=_-]+         { printf("Valid URL: %s\n", yytext); }

// Valid identifier: Starts with a letter or underscore, followed by letters, digits, or underscores
[_a-zA-Z][_a-zA-Z0-9]*                     { printf("Valid Identifier: %s\n", yytext); }

// Valid date: dd/mm/yyyy format
[0-3][0-9]/[0-1][0-9]/[0-9]{4}             { printf("Valid Date: %s\n", yytext); }

// Valid time: hh:mm:ss format
([01][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]  { printf("Valid Time: %s\n", yytext); }

.                                          ; // Ignore other characters

%%

int yywrap() { return 1; }

int main(int argc, char **argv) {
    yylex();
    return 0;
}
