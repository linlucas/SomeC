#include <stdio.h>
#include <stdlib.h>

char line[256];
char *end;
long operator, operand;

int checkIfDividesEvenly() {
    puts("Check if two numbers divide evenly.");
    puts("Enter the number you want to divide with:");
    fgets(line, sizeof(line), stdin);
    operator = strtol(line, &end, 10);

    puts("Enter the number you want to divide by:");
    fgets(line, sizeof(line), stdin);
    operand = strtol(line, &end, 10);

    if (operator % operand) {
        printf("%li and %li does NOT divide cleanly.", operator, operand);
    } else {
        printf("%li and %li divides evenly.", operator, operand);
    }
    return 0;
}