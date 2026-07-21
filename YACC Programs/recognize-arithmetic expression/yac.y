// Write a program using YACC to recognise a valid arithmetic expression that uses operators such as +, -, * or /.
// This is the yacc/bison code.
%{
#include<stdio.h>
#define YYSTYPE double // Defines YYSTYPE as double. This means that the parser will use double for its values (like numbers).
%}

%token DIGIT ID NL 
%left '-' '+'  //order and precedence of operators
%left '*' '/' 

%% 
exp :exp '+' exp 
| exp '-' exp 
| exp '*' exp 
| exp '/' exp 
|'(' exp ')' 
| ID 
| DIGIT; 
%% 

void main ()
{
printf("Enter the exp: "); 
yyparse(); // it will initiate the yacc program.Calls the parser to read and process the input.
Printf(“\n expression is valid”);
} 
int yyerror(char *msg) // This function is called when there is a syntax error in the input. It currently just prints "Invalid string".
{ 
printf("Invalid string"); 
}
