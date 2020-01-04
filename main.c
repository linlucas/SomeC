#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define forEach(item, array) \
    for(int keep = 1, count = 0, size = sizeof(array) / sizeof( *(array)); \
    keep && count != size; \
    keep = !keep, ++count) \
    for(item = (array) + count; keep; keep = !keep)

struct customer {
    char firstName[32];
    char lastName[32];
    char citizenship[32];
    int age;
    int phoneNum;
    double balance;
};

char line[256];
char *end;
struct customer customerList[1048];
int mainMenuChoice;

struct customer openNewAccount();
void viewCustomerList();

int main() {
    struct customer wow = {"Lucas", "Lin", "United States", 18,
            2067195611, 123.50};
    struct customer cool = {"Emma", "Lau", "United States", 18,
            234433423, 134.20};
    struct customer somthing = {"Alex", "Rigor", "United States", 19,
            234242345, 100};
    customerList[0] = wow;
    customerList[1] = cool;
    customerList[2] = somthing;


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
            case 2:
                viewCustomerList();
        }
    }
}

struct customer openNewAccount() {
    char *token;
    struct customer thisCustomer = {};

    puts("What is your full name?");
    if (fgets(line, sizeof(line), stdin)) {
        token = strtok(line, " ");
        strcpy(thisCustomer.firstName, token);
        token = strtok(NULL, " ");
        strcpy(thisCustomer.lastName, token);
        strtok(thisCustomer.lastName, "\n");
    }

    printf("Hi %s, which country does your citizenship reside in?\n", thisCustomer.firstName);
    if (fgets(line, sizeof(line), stdin)) {
        strcpy(thisCustomer.citizenship, line);
    }
    puts("What is your age?");
    if (fgets(line, sizeof(line), stdin)) {
        thisCustomer.age = (int) strtol(line, &end, 10);
    }
    puts("What is your phone number?");
    if (fgets(line, sizeof(line), stdin)) {
        thisCustomer.phoneNum = (int) strtol(line, &end, 10);
    }
    puts("How much money would you like to deposit today?");
    if (fgets(line, sizeof(line), stdin)) {
        thisCustomer.balance = strtod(line, &end);
    }
    return thisCustomer;
}

void viewCustomerList() {
    int i = 1;

    forEach(struct customer *pCustomer, customerList) {
        printf("Customer #%d\nName: %s\nAge: %d\nPhone Number: %d", i, pCustomer->firstName, pCustomer->age,
                pCustomer->phoneNum);
    }
}