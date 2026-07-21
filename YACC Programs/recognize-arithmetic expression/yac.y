// Write a program using YACC to recognise a valid arithmetic expression that uses operators such as +, -, * or /.
// This is the yacc/bison code.
%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyerror(const char *s);
%}
%token DIGIT ID NL
%left '+' '-'
%left '*' '/'
%%
/* Allows both standard expressions (a+b) AND assignments (c=a+b) */
stmt: ID '=' exp NL {
printf("\nExpression is valid\n");
exit(0);
}
| exp NL {
printf("\nExpression is valid\n");

exit(0);
};
exp: exp '+' exp
| exp '-' exp
| exp '*' exp
| exp '/' exp
| '(' exp ')'
| ID
| DIGIT;
%%
int main() {
printf("Enter the exp: ");
yyparse();
return 0;
}
int yyerror(const char *s) {
printf("\nInvalid Expression\n");
exit(0);
}
