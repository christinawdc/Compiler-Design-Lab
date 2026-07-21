// Write a program using YACC to recognise a valid arithmetic expression that uses operators such as +, -, * or /.
// This is the yacc/bison code.
%{
#include <stdio.h>
#include <stdlib.h>

// Declare yylex and yyerror to prevent implicit declaration compiler errors
int yylex(void);
void yyerror(const char *s);
%}

%token DIGIT ID NL 
%left '+' '-'  //order and precedence of operators
%left '*' '/'

%%
// Top-level start rule requiring a newline at the end
stmt: exp NL { 
        printf("Valid expression\n"); 
        exit(0); 
      }
    ;

exp : exp '+' exp 
    | exp '-' exp 
    | exp '*' exp 
    | exp '/' exp 
    | '(' exp ')' 
    | ID 
    | DIGIT
    ;
%%

int main(void) {
    printf("Enter the exp: "); 
    yyparse(); / it will initiate the yacc program.Calls the parser to read and process the input.
    return 0;
}

void yyerror(const char *msg) {
    printf("Invalid string\n"); // This function is called when there is a syntax error in the input. It currently just prints "Invalid string".
    exit(0);
}
