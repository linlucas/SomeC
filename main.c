#include <stdio.h>

enum color {
    red, green, blue, yellow
};

int main() {
    enum color screenColor = red;
    printf("%d is the number", screenColor);
}