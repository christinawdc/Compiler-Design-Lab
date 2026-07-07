// Design and implement a lexical analyzer using C language to recognize all valid tokens in the input program.
// The lexical analyzer should ignore redundant spaces, tabs and newlines. It should also ignore comments.

%{
#include <stdio.h>
#include <stdlib.h>
int n = 0;
int k = 0, i = 0, o = 0, num = 0;
%}

%%
if|else|while|int|switch|for|char   { printf("%s is a keyword\n", yytext); k++; n++; }
[_a-zA-Z][_a-zA-Z0-9]* { printf("%s is an identifier\n", yytext); i++; n++; }
"="|"+"|"-"|"*"|"/"|"<"|">"          { printf("%s is an operator\n", yytext); o++; n++; }
[0-9]+                               { printf("%s is a number\n", yytext); num++; n++; }
[ \t]+                               ; /* Ignore whitespace */
\n                                   { return 0; /* Ends parsing on Enter */ }
.                                    ; /* Ignore other characters */
%%

int main() {
   printf("Enter the input text:\n");
   yylex();
   printf("\n--- Token Summary ---\n");
   printf("Total Tokens : %d\n", n);
   printf("Keywords     : %d\n", k);
   printf("Identifiers  : %d\n", i);
   printf("Operators    : %d\n", o);
   printf("Numbers      : %d\n", num);
   return 0;
}

int yywrap() {
   return 1;
}
