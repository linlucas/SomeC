#include <stdio.h>
#include <string.h>

// Make a file, write the user's name in it, and add "something" between the
// first and last name.
int fileMain() {
    char firstName[20];
    char lastName[20];
    FILE* pFile;

    puts("What is your first name?");
    fgets(firstName, 20, stdin);
    strtok(firstName, "\n");

    printf("Hi %s, what is your last name?\n", firstName);
    fgets(lastName, 20, stdin);
    strtok(lastName, "\n");

    pFile = fopen("something.txt", "w");
    fprintf(pFile, "%s %s", firstName, lastName);

    // SEEK_SET as opposed to SEEK_END which moves the cursor from the back
    fseek(pFile, strlen(firstName) + 1, SEEK_SET);
    fprintf(pFile, "something %s", lastName);
}