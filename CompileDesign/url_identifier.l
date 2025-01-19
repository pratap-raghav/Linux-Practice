%{
#include<stdio.h>
%}

PROTOCOL (http|https):\/\/
WWW www\.
DOMAIN [a-zA-Z0-9\-]+\.(com|org|net|edu|gov|in)
PATH (\/[a-zA-Z0-9\-\._~%!$&'()*+,;=:@]*)*
QUERY (\?[a-zA-Z0-9\-\._~%!$&'()*+,;=:@\/?]*)
FRAGMENT (\#[a-zA-Z0-9\-\._~%!$&'()*+,;=:@\/?]*)

URL ({PROTOCOL}|{WWW}){DOMAIN}{PATH}?{QUERY}?{FRAGMENT}?

%%
{URL}   { printf("Valid URL: %s\n", yytext); }
.       { /* ignore other characters */ }
%%

int yywrap() { return 1; }


int main()
{
    yylex();
    return 0;
}
