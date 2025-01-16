#include <ctype.h>
#include <stdio.h>  
#include "read_line.h"


// This is an utility function to read a line of text.
// It manages input better than a basic scanf.
int read_line(char str[], int n) {
    int ch, i = 0;
    // Here we skip initiate whitespace.
    while (isspace(ch = getchar()));
    // Here we start storing characters.
    str[i++] = ch;
    // Here we continue until the newline.
    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0'; // Terminate the string null.
    return i; // Here we return no of characters read.
}
