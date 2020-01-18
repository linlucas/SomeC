#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define forEach(item, array) \
    for (int keep = 1, count = 0, size = sizeof(array) / sizeof( *(array)); \
    keep && count != size; \
    keep = !keep, ++count) \
    for (item = (array) + count; keep; keep = !keep)
#define getInput(line) if (fgets(line, sizeof(line), stdin))
#define removeNewline(line) strtok(line, "\n")

struct user {
    char firstName[32];
    char lastName[32];
    char citizenship[32];
    int age;
    int phoneNum;
    double balance;
};

char line[256];
char *end;
struct user userList[256];
int mainMenuChoice;

struct user openNewAccount();
void viewCustomerList();
void editAccountInfo();
void makeTransaction();
void eraseAccount();
void viewFullAccountInfo();
int getUserIndex();

int bankingMain() {
    int emptyIndex = 0;
    bool goAgain = false;

    do {
        puts("Welcome to the banking system:");
        puts("1. Open a new account");
        puts("2. View a list of customers");
        puts("3. Edit account information");
        puts("4. Make a transaction");
        puts("5. Erase an account");
        puts("6. View full account information");

        getInput(line) {
            mainMenuChoice = (int) strtol(line, &end, 10);
            switch (mainMenuChoice) {
                case 1:
                    for (int i = 0; i <= 256; ++i) {
                        if (userList[i].age == 0) {
                            emptyIndex = i;
                            break;
                        }
                    }
                    userList[emptyIndex] = openNewAccount();
                    break;
                case 2:
                    viewCustomerList();
                    break;
                case 3:
                    editAccountInfo();
                    break;
                case 4:
                    makeTransaction();
                    break;
                case 5:
                    eraseAccount();
                    break;
                case 6:
                    viewFullAccountInfo();
                    break;
                default:
                    puts("Invalid choice, please input a number from 1-6.");
                    break;
            }
        }

        puts("Do you have another transaction? (yes/no)");
        getInput(line) {
            strtok(line, "\n");
            goAgain = strcmp(line, "yes") == 0 ? true : false;
        }
        if (!goAgain) {
            puts("Thank you for banking with us!");
        }
    } while (goAgain);
    return 0;
}

struct user openNewAccount() {
    char *token;
    struct user thisCustomer = {};

    puts("What is your full name?");
    getInput(line) {
        token = strtok(line, " ");
        strcpy(thisCustomer.firstName, token);
        token = strtok(NULL, " ");
        strcpy(thisCustomer.lastName, token);
        strtok(thisCustomer.lastName, "\n");
    }

    printf("Hi %s, which country does your citizenship reside in?\n", thisCustomer.firstName);
    getInput(line) {
        strtok(line, "\n");
        strcpy(thisCustomer.citizenship, line);
    }
    puts("What is your age?");
    getInput(line) {
        thisCustomer.age = (int) strtol(line, &end, 10);
    }
    puts("What is your phone number?");
    getInput(line) {
        thisCustomer.phoneNum = (int) strtol(line, &end, 10);
    }
    puts("How much money would you like to deposit today?");
    getInput(line) {
        thisCustomer.balance = strtod(line, &end);
    }
    return thisCustomer;
}

void viewCustomerList() {
    int i = 1;

    if (userList[0].age == 0) {
        puts("No user in the database.");
    }
    forEach(struct user *pCustomer, userList) {
            if (pCustomer->age == 0) {
                break;
            }
            printf("Customer #%d\nName: %s\nAge: %d\nPhone Number: %d\n\n",
                    i, pCustomer->firstName, pCustomer->age,
                   pCustomer->phoneNum);
            ++i;
        }
}

void editAccountInfo() {
    int thisPhoneNum = 0, userIndex = 0, thisChoice = 0, i;

    puts("What is your phone number?");
    getInput(line) {
        thisPhoneNum = (int) strtol(line, &end, 10);
    }
    for (i = 0; i < 256; ++i) {
        if (userList[i].phoneNum == thisPhoneNum) {
            userIndex = i;
            break;
        }
    }
    if (i == 256) {
        puts("Sorry, this user doesn't exist in our database.");
        return;
    } else {
        printf("Hi %s, what would you like to change?\n", userList[userIndex].firstName);
        puts("1. Name");
        puts("2. Citizenship");
        puts("3. Age");
        puts("4. Phone Number");
        getInput(line) {
            thisChoice = (int) strtol(line, &end, 10);
        }
        switch (thisChoice) {
            case 1:
                puts("Input your first name:");
                getInput(line) {
                    removeNewline(line);
                    strcpy(userList[userIndex].firstName, line);
                }
                puts("Input your last name:");
                getInput(line) {
                    removeNewline(line);
                    strcpy(userList[userIndex].lastName, line);
                }
                break;
            case 2:
                puts("What country does the changed citizenship reside in?");
                getInput(line) {
                    removeNewline(line);
                    strcpy(userList[userIndex].citizenship, line);
                }
                break;
            case 3:
                puts("What is the changed age?");
                getInput(line) {
                    userList[userIndex].age = (int) strtol(line, &end, 10);
                }
                break;
            case 4:
                puts("What is the new phone number?");
                getInput(line) {
                    thisPhoneNum = (int) strtol(line, &end, 10);
                    userList[userIndex].phoneNum = thisPhoneNum;
                }
                break;
            default:
                puts("Invalid choice, choose a number between 1-4");
        }
    }
}

void makeTransaction() {
    int userIndex = 0;

    puts("What is your phone number?");
    userIndex = getUserIndex();
    printf("Hi %s, please enter 1 for deposit, 2 for withdrawal\n", userList[userIndex].firstName);
    getInput(line) {
        if (strtol(line, &end, 10) == 1) {
            puts("How much would you like to deposit?");
            getInput(line) {
                userList[userIndex].balance += strtod(line, &end);
            }
            puts("Account updated.");
        } else {
            puts("How much would you like to withdraw?");
            getInput(line) {
                userList[userIndex].balance -= strtod(line, &end);
            }
            puts("Account updated.");
        }
    }
}

void eraseAccount() {
    int userIndex;

    puts("Please enter the phone number for the account you want to delete:");
    userIndex = getUserIndex();
    printf("%s, are you sure you want to erase everything? (yes/no)\n", userList[userIndex].firstName);
    getInput(line) {
        if (strcmp(strtok(line, "\n"), "yes") == 0) {
            userList[userIndex].age = 0;
        }
    }
}

void viewFullAccountInfo() {
    int userIndex;
    struct user thisUser;

    puts("Please enter your phone number:");
    userIndex = getUserIndex();
    thisUser = userList[userIndex];

    printf("Name: %s %s\nCitizenship: %s\nAge: %d\nPhone number: %d\nBalance: %.2f\n",
           thisUser.firstName, thisUser.lastName, thisUser.citizenship, thisUser.age,
           thisUser.phoneNum, thisUser.balance);
}

int getUserIndex() {
    int thisPhoneNum = 0, i;

    getInput(line) {
        thisPhoneNum = (int) strtol(line, &end, 10);
    }
    for (i = 0; i < 256; ++i) {
        if (userList[i].phoneNum == thisPhoneNum) {
            return i;
        }
    }
    puts("This user does not exist!");
    return -1;
}
