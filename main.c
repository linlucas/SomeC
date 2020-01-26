#include <stdio.h>
#include <ctype.h>
#define KEY '*'

int main(void) {
    int ch, newch;
    while ((ch = fgetc(stdin)) != '\n') {
        newch = ch ^ KEY;
        if (isprint(ch) && isprint(newch)) {
            putchar(newch);
        } else {
            putchar(ch);
        }
    }
}