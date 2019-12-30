#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date {
    int month;
    int day;
    int year;
};

struct date getInput(void);
int getComparableDateValue(struct date someDate);

int elapsedMain() {
    struct date firstDate, secondDate;
    int firstComparableVal, secondComparableVal;

    puts("This program will determine the number of days elapsed between 2 dates.");
    puts("Please enter your first date in the following format:");
    puts("mm/dd/yyyy, e.g. 05/23/2001");
    firstDate = getInput();
    firstComparableVal = getComparableDateValue(firstDate);

    puts("Please enter your second date:");
    secondDate = getInput();
    secondComparableVal = getComparableDateValue(secondDate);

    printf("Your first date is %d days away from the second date.", secondComparableVal - firstComparableVal);
    return 0;
}

struct date getInput(void) {
    char line[256];
    char *end, *token;
    int month, day, year;
    _Bool isDateValid;

    do {
        fgets(line, sizeof(line), stdin);
        token = strtok(line, "/");
        month = (int) strtol(token, &end, 10);
        token = strtok(NULL, "/");
        day = (int) strtol(token, &end, 10);
        token = strtok(NULL, "/");
        year = (int) strtol(token, &end, 10);

        if (month > 12 || month < 1 || day > 31 || day < 1 || year < 1900) {
            isDateValid = 0;
            printf("%d/%d/%d is not a valid date!\n", month, day, year);
            puts("Please enter a valid date:");
        } else {
            isDateValid = 1;
        }
    } while (!isDateValid);

    return (struct date) {month, day, year};
}

int getComparableDateValue(struct date someDate) {
    int f, g;

    f = (someDate.month <= 2) ? someDate.year - 1 : someDate.year;
    g = (someDate.month <= 2) ? someDate.month + 13 : someDate.month + 1;
    return 1461 * f / 4 + 153 * g / 5 + someDate.day;
}

