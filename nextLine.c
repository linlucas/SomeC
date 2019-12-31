#include <stdio.h>

void readLine(char line[]);

int nextLineMain() {
    char line[256];
    readLine(line);
    printf("%s", line);
    return 0;
}

void readLine(char line[]) {
    unsigned char ch;
    int i = 0;

    do {
        ch = getchar();
        line[i] = (char) ch;
        ++i;
    } while (ch != '\n');
    line[i + 1] = '\0';
}