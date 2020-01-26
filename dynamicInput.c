#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10

// assume that caller calls free, always add NUL to the end
char *dynamic_next_le(void) {
    char *input = malloc(INITIAL_SIZE + 1);
    if (!(input)) exit(EXIT_FAILURE);
    char *traverser = input;
    int ch;
    size_t len = 0, addedLen = 0;


    for (;;) {
        ch = fgetc(stdin);
        if (ch == '\n') break;

        if (++len > INITIAL_SIZE + addedLen) {
            input = realloc(input, INITIAL_SIZE + addedLen + 10);
            if (!(input)) exit(EXIT_FAILURE);
            addedLen += 10;
        }
        *traverser++ = (char) ch;
    }
    *traverser = '\0';
    return input;
}