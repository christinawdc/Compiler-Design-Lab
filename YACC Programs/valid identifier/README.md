
## COMPILATION & EXECUTION INSTRUCTIONS

1. Save the Lex code as **`lexc2.l`**.
2. Save the Yacc/Bison code as **`yac2.y`**.
3. Run the following commands in the terminal:

```bash
# 1. Generate YACC files
yacc -d yac2.y

# 2. Generate Lex files
lex lexc2.l

# 3. Compile the generated C code
gcc lex.yy.c y.tab.c -o identifier_check

# 4. Run the executable
./identifier_check
