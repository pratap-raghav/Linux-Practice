%{
#include "y.tab.h"
%}

%%
[0] { return '0'; }
[1] { return '1'; }
[\n] { return 0; } // End of input
[ \t] { /* Ignore whitespace */ }
. { printf("Invalid character: %s\n", yytext); exit(1); }

%%
int yywrap() {
    return 1;
}
