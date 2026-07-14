#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a keyword
int isKeyword(char buffer[]) {
    // Array of standard C keywords (expandable up to 32 as per requirements)
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    
    for (int i = 0; i < 32; i++) {
        if (strcmp(keywords[i], buffer) == 0) {
            return 1; // It is a keyword
        }
    }
    return 0; // It is not a keyword
}

int main() {
    char ch;
    char buffer[15];
    char operators[] = "+-*/%=";
    FILE *fp;
    int j = 0;

    // Opening the input file in read mode
    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error while opening the file. Ensure 'input.txt' exists.\n");
        exit(0);
    }

    // Processing the file character by character
    while ((ch = fgetc(fp)) != EOF) {
        
        // Check if character is an operator
        int isOperator = 0;
        for (int i = 0; i < 6; i++) {
            if (ch == operators[i]) {
                isOperator = 1;
                break;
            }
        }

        if (isOperator) {
            // If there's something in the buffer, process it before handling the operator
            if (j != 0) {
                buffer[j] = '\0';
                j = 0;
                if (isKeyword(buffer)) {
                    printf("%s is a keyword\n", buffer);
                } else {
                    printf("%s is an identifier\n", buffer);
                }
            }
            printf("%c is an operator\n", ch);
        }
        // Check if character is alphanumeric
        else if (isalnum(ch)) {
            buffer[j++] = ch;
        }
        // Check for delimiters (space, newline, tab)
        else if (isspace(ch) && j != 0)
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer)) {
                printf("%s is a keyword\n", buffer);
            } else {
                printf("%s is an identifier\n", buffer);
            }
        }
    }

    // Handle any leftover token in the buffer at the end of the file
    if (j != 0) {
        buffer[j] = '\0';
        if (isKeyword(buffer)) {
            printf("%s is a keyword\n", buffer);
        } else {
            printf("%s is an identifier\n", buffer);
        }
    }

    fclose(fp);
    return 0;
}
