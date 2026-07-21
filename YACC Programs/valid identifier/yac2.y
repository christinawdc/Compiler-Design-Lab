%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(const char *s);
%}

%token ID NL

%%
/* Production rule: statement must be an identifier followed by a newline */
stmt: exp NL {
    printf("Valid Identifier\n");
    exit(0);
};

exp: ID ;
%%

int main() {
    printf("Enter the token: ");
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    printf("Invalid Identifier\n");
    exit(0);
}
