#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10

char *dynamic_next_line(void) {
    char *input = malloc(INITIAL_SIZE + 1);
    char *currentPos = input;
    int ch;
    size_t len = 0, addedLen = 0;

    if (!(input)) exit(EXIT_FAILURE);

    for (;;) {
        ch = fgetc(stdin);
        if (ch == '\n') break;

        if (++len > INITIAL_SIZE + addedLen) {
            input = realloc(input, INITIAL_SIZE + addedLen + 10);
            if (!(input)) exit(EXIT_FAILURE);
            addedLen += 10;
        }
        *currentPos++ = (char) ch;
    }
    *currentPos = '\0';
    return input;
}