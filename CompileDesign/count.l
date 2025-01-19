%{
#include<stdio.h>
%}

%{
int spaces = 0, words = 0, lines = 0;
%}

%%
" "     { spaces++; }
\n      { lines++; }
[^\n\t ]+   { words++; }
%%

int yywrap() { return 1; }


int main() {
    yylex();
    printf("Blank Spaces: %d\n", spaces);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
    return 0;
}
