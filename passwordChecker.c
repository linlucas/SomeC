#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1;

char password[10];
int hasUpperCaseLetter, hasNum, hasSymbol;

int passwordMain() {
    int passwordLen;
    puts("Your password have to contain a uppercase letter, a number, and a symbol.");
    puts("It also have to be less than 10 characters.");
    puts("Please enter your password: ");
    scanf("%s", password);

    passwordLen = strlen(password);
    for (int i = 0; i < passwordLen; ++i) {
        if (isalpha(password[i])) {
            if (isupper(password[i])) {
                hasUpperCaseLetter = TRUE;
            }
        } else if (isnumber(password[i])) {
            hasNum = TRUE;
        } else {
            hasSymbol = TRUE;
        }
    }

    if (hasUpperCaseLetter && hasNum && hasSymbol) {
        printf("Your password \"%s\" is secure.\n", password);
    } else {
        printf("Your password \"%s\" is NOT secure.\n", password);
    }
    return 0;
}