#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Check if a buffer is a keyword
int isKeyword(char buffer[]) {
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    for (int i = 0; i < 32; i++) {
        if (strcmp(keywords[i], buffer) == 0) return 1;
    }
    return 0;
}

// Check if a buffer is a numeric constant
int isConstant(char buffer[]) {
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (!isdigit(buffer[i]) && buffer[i] != '.') return 0;
    }
    return 1;
}

// Process and print what is currently inside the buffer
void processBuffer(char buffer[], int *j) {
    if (*j > 0) {
        buffer[*j] = '\0';
        *j = 0; // Reset buffer index
        
        if (isKeyword(buffer)) {
            printf("%-15s is a keyword\n", buffer);
        } else if (isConstant(buffer)) {
            printf("%-15s is a constant\n", buffer);
        } else {
            printf("%-15s is an identifier\n", buffer);
        }
    }
}

int main() {
    char ch, next_ch;
    char buffer[15];
    char operators[] = "+-*/%=";
    FILE *fp = fopen("input.txt", "r");
    int j = 0;

    if (fp == NULL) {
        printf("Error opening 'input.txt'.\n");
        exit(0);
    }

    while ((ch = fgetc(fp)) != EOF) {
        
        // 1. Skip Preprocessor Directives (like #include or #define)
        if (ch == '#') {
            while ((ch = fgetc(fp)) != '\n' && ch != EOF);
            continue;
        }

        // 2. Handle Comments and Division Operator
        if (ch == '/') {
            next_ch = fgetc(fp);
            
            // Single-line comment: Skip until newline
            if (next_ch == '/') {
                processBuffer(buffer, &j);
                while ((ch = fgetc(fp)) != '\n' && ch != EOF);
                continue;
            }
            // Multi-line comment: Skip until */
            else if (next_ch == '*') {
                processBuffer(buffer, &j);
                while (1) {
                    ch = fgetc(fp);
                    if (ch == EOF) break;
                    if (ch == '*') {
                        if ((next_ch = fgetc(fp)) == '/') break;
                        else ungetc(next_ch, fp);
                    }
                }
                continue;
            }
            // Not a comment, just a division operator
            else {
                ungetc(next_ch, fp); 
            }
        }

        // 3. Handle Operators
        if (strchr(operators, ch)) {
            processBuffer(buffer, &j);
            printf("%-15c is an operator\n", ch);
        }
        // 4. Accumulate Alphanumeric Characters & Underscores
        else if (isalnum(ch) || ch == '_') {
            buffer[j++] = ch;
        }
        // 5. Treat whitespace and punctuation (like ;, (, ), {, }) as separators
        else if (isspace(ch) || strchr(";,(){}[].", ch)) {
            processBuffer(buffer, &j);
        }
    }

    // Process any leftover token at the end of the file
    processBuffer(buffer, &j);

    fclose(fp);
    return 0;
}
