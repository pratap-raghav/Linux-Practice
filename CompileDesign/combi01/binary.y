%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
binary: '0' { printf("Recognized: 0\n"); }
      | '1' { printf("Recognized: 1\n"); }
      | binary '0' { printf("Recognized: 0\n"); }
      | binary '1' { printf("Recognized: 1\n"); }
      ;

%%

int main() {
    printf("Enter a binary sequence (0s and 1s):\n");
    yyparse();
    printf("Valid binary sequence.\n");
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid input.\n");
    exit(1);
}
