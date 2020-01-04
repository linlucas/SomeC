#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char line[256];
char *end;
int mainMenuChoice;

struct customer {
    char firstName[32];
    char lastName[32];
    char citizenship[32];
    double balance;
    int age;
    int phoneNum;
};

struct customer openNewAccount();

int main() {
    puts("Welcome to the banking system:");
    puts("1. Open a new account");
    puts("2. View a list of customers");
    puts("3. Edit account information");
    puts("4. Make a transaction");
    puts("5. Erase an account");
    puts("6. View full account information");

    if (fgets(line, sizeof(line), stdin)) {
        mainMenuChoice = (int) strtol(line, &end, 10);
        switch (mainMenuChoice) {
            case 1:
                openNewAccount();
                break;

        }
    }
}

struct customer openNewAccount() {
    char *token;
    struct customer thisCustomer;

    puts("Hello, what is your full name?");
    if (fgets(line, sizeof(line), stdin)) {
        token = strtok(line, " ");
        strcpy(thisCustomer.firstName, token);
        token = strtok(NULL, " ");
        strcpy(thisCustomer.lastName, token);
        strtok(thisCustomer.lastName, "\n");
    }

    puts("Which country does your citizenship reside in?");
    if (fgets(line, sizeof(line), stdin)) {
        strcpy(thisCustomer.citizenship, line);
    }

    printf("%s %s %s", thisCustomer.firstName, thisCustomer.lastName, thisCustomer.citizenship);



}