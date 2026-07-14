#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a keyword
int checkBuffer(char buffer[]) {
    // Array of standard C keywords 
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    
    for (int i = 0; i < 32; i++) {
        if (strcmp(keywords[i], buffer) == 0) {
            printf("%s is a keyword\n", buffer);
            return;
        }
    }
    printf("%s is an identifier\n",buffer);
}

int main() {
    char ch, buffer[15], operators[] = "+-*/%=";
    FILE *fp= fopen("input.txt", "r");;
    int j = 0;

    if (!fp) {
        printf("Error opening file.\n");
        exit(0);
    }

    // Processing the file character by character
    while ((ch = fgetc(fp)) != EOF) {
        
        // Check if character is an operator
        if (strchr(operators, ch)) {
            if (j > 0) { buffer[j] = '\0'; j = 0; checkBuffer(buffer); }
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
        }
    }

    // Process leftover token at End-Of-File
    if (j != 0) {
        buffer[j] = '\0';
        checkBuffer(buffer);
    }
    fclose(fp);
    return 0;
}
