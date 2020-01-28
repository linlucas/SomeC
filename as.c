#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("something.txt", "r");
    fputc(fgetc(file), stdout);
}