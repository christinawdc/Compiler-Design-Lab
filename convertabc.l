// Program in Lex to convert abc to ABC from a string.

%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
"abc"   { printf("ABC"); } /* Replace 'abc' with 'ABC' */
.       { printf("%s", yytext); } /* Print any other character as it is */
\n      { printf("%s", yytext); return 0; } /* Print newline and stop on Enter */
%%

int main() {
    printf("Enter the String: ");
    yylex(); // Start the lexical analyzeR
    return 0;
}

int yywrap() {
    return 1;
}
