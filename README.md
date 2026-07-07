# Lex (Flex) Basics

A beginner-friendly introduction to **Lex (Flex)** with simple examples used in compiler design laboratories.

## What is Lex?

Lex (or Flex) is a tool used to generate a **Lexical Analyzer (Scanner)**.

A lexical analyzer reads a program and breaks it into **tokens**, which are the smallest meaningful units of a program.

Example:

```c
int a = 10;
```

Tokens:

| Input | Token |
|-------|-------|
| int | Keyword |
| a | Identifier |
| = | Operator |
| 10 | Number |
| ; | Delimiter |

---

# Compiler Phases

```
Source Program
      │
      ▼
Lexical Analysis
      │
Syntax Analysis
      │
Semantic Analysis
      │
Intermediate Code
      │
Optimization
      │
Target Code
```

Lex is used in the **Lexical Analysis** phase.

---

# Types of Tokens

## Keywords

Reserved words in C.

```
int
char
if
else
while
for
switch
return
```

---

## Identifiers

Names given by the programmer.

Examples

```
sum
marks
student1
_temp
```

Rules

- Begins with a letter or `_`
- Cannot start with a digit
- May contain digits
- No spaces

---

## Operators

```
+
-
*
/
=
<
>
==
<=
>=
```

---

## Numbers

```
10
25
100
999
```

---

## Delimiters

```
;
,
(
)
{
}
```

---

# Structure of a Lex Program

Every Lex program contains three sections.

```lex
%{
Declarations
%}

%%
Rules
%%

Functions
```

---

## Section 1 - Declarations

```lex
%{
#include<stdio.h>
int count=0;
%}
```

Used for

- Header files
- Global variables
- Function declarations

---

## Section 2 - Rules

```lex
%%
Pattern     Action
%%
```

Example

```lex
[0-9]+
{
    printf("Number");
}
```

---

## Section 3 - User Functions

```c
int main()
{
    yylex();
}

int yywrap()
{
    return 1;
}
```

---

# Important Lex Functions

## yylex()

Starts lexical analysis.

```c
yylex();
```

---

## yytext

Stores the matched token.

Example

Input

```
hello
```

Rule

```lex
[a-z]+
{
    printf("%s",yytext);
}
```

Output

```
hello
```

---

## yywrap()

Executed when the input ends.

```c
int yywrap()
{
    return 1;
}
```

---

## yyin

Reads input from a file.

```c
yyin=fopen("input.txt","r");
```

---

# Regular Expressions

| Pattern | Meaning |
|----------|---------|
| `[a-z]` | Lowercase letter |
| `[A-Z]` | Uppercase letter |
| `[0-9]` | Digit |
| `[a-zA-Z]` | Alphabet |
| `[0-9]+` | One or more digits |
| `[a-z]+` | One or more lowercase letters |
| `[_a-zA-Z][_a-zA-Z0-9]*` | Identifier |
| `[ \t]+` | Space or tab |
| `\n` | New line |
| `.` | Any character |
| `*` | Zero or more |
| `+` | One or more |

---

# How Lex Matches Patterns

Lex follows two rules:

### 1. Longest Match

```
ifelse
```

Matches

```
[a-z]+
```

instead of

```
if
```

because it is longer.

### 2. First Rule Wins

If two patterns match the same text, the one that appears first in the file is selected.

---

# Compiling a Lex Program

Generate the C source

```bash
lex program.l
```

This creates

```
lex.yy.c
```

Compile

```bash
gcc lex.yy.c -ll
```

or (Flex)

```bash
gcc lex.yy.c -lfl
```

Run

```bash
./a.out
```

---

# Lab Programs Included

## 1. Lexical Analyzer

Recognizes

- Keywords
- Identifiers
- Operators
- Numbers

---

## 2. Count Lines, Words and Characters

Counts

- Lines
- Words
- Characters
- Spaces

---

## 3. Replace "abc" with "ABC"

Example

Input

```
Pythonabc RATaabc
```

Output

```
PythonABC RATaABC
```

---

## 4. Count Vowels and Consonants

Example

Input

```
Python Programming
```

Output

```
Vowels: 4
Consonants: 13
```

---

# Frequently Used Lex Functions

| Function | Purpose |
|----------|---------|
| `yylex()` | Starts scanning |
| `yytext` | Current matched token |
| `yywrap()` | Called at end of input |
| `yyin` | Reads input from file |

---

# Lex vs Yacc

| Lex | Yacc |
|------|------|
| Generates scanner | Generates parser |
| Uses Regular Expressions | Uses Context-Free Grammar |
| First compiler phase | Second compiler phase |

---

# Common Viva Questions

- What is Lex?
- What is Flex?
- What is a lexical analyzer?
- What is a token?
- What are keywords?
- What are identifiers?
- What is `yytext`?
- What is `yylex()`?
- What is `yywrap()`?
- What is `yyin`?
- What is a regular expression?
- What are the three sections of a Lex program?
- Which file does Lex generate?
- How do you compile a Lex program?
- What is the difference between `*` and `+`?
- Why should keyword rules appear before identifier rules?

---

# Quick Revision

- Lex generates a lexical analyzer.
- Tokens are the smallest meaningful units of a program.
- Lex programs have three sections.
- `yylex()` starts scanning.
- `yytext` stores the current token.
- `yywrap()` is called when input ends.
- `yyin` reads input from a file.
- Lex uses regular expressions to recognize tokens.
- Longest match wins.
- If lengths are equal, the first rule wins.
