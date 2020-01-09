#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(const char *);

int main(void) {
    char *something = "hi";
    char *hello = duplicate(something);
    printf("%s", hello);
}

char *duplicate(const char *pString) {
    char *pNew = malloc(sizeof(*pString) + 1);
    if (!pString) {
        return NULL;
    }
    strcpy(pNew, pString);
    free(pNew);
    return pNew;
}