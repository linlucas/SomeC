#include <stdio.h>

int getLength(const char *string);
void copyString(char *result, char *string);

int stringMain() {
    char something[] = "hello there";
    char other[20];
    printf("%d\n", getLength(something));
    copyString(other, something);
    printf("%s", other);
    return 0;
}

int getLength(const char *string) {
    int i = 0;
    while (*string) {
        ++string, ++i;
    }
    return i;
}

void copyString(char *result, char *string) {
    while (*string) {
        *result++ = *string++;
    }
    *result = '\0';
}