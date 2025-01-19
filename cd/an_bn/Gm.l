%{
#include "y.tab.h"
%}

%%
"a"|"A"   { return A; }
"b"|"B"   { return B; }
[ \t]     { /* Ignore whitespace */ }
\n        { return 0; }  // End of input
.         { return yytext[0]; }  // Catch-all for invalid characters
%%

int yywrap() 
{ 
    return 1; 
}
