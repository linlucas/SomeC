#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define chkin(line) \
    if (fgets(line, sizeof(line), stdin) == NULL || strcmp(line, "\n") == 0) { \
    puts("Error occurred while taking input."); \
    exit(EXIT_FAILURE); \
    };

struct class {
    char name[20];
    double gpaEq;
} *pClassList;

char line[256], name[20], grade;
char *token, *end;
int classCount;
double total, gpa;

int GPAmain(void) {

    puts("Welcome to the GPA calculator");
    puts("What's your first name?");
    chkin(line)
    strtok(line, "\n");
    strcpy(name, line);

    printf("Hi %s, how many classes did you take this semester?\n", name);
    chkin(line)
    classCount = (int) strtol(line, &end, 10);

    pClassList = (struct class *) malloc(classCount * sizeof(struct class));
    if (!pClassList) puts("There's not enough memory!");

    for (int i = 0; i < classCount; ++i) {
        printf("Please enter the name of class #%d:\n", i + 1);
        chkin(line)
        strcpy(pClassList[i].name, strtok(line, "\n"));
        printf("Please enter your grade for the class:\n");
        chkin(line)
        grade = line[0];

        switch (grade) {
            case 'a':
            case 'A':
                pClassList[i].gpaEq = 4.0;
                break;
            case 'b':
            case 'B':
                pClassList[i].gpaEq = 3.0;
                break;
            case 'c':
            case 'C':
                pClassList[i].gpaEq = 2.0;
                break;
            case 'd':
            case 'D':
                pClassList[i].gpaEq = 1.0;
                puts("That's pretty bad...");
                break;
            default:
                puts("Wow you suck");
                break;
        }
    }

    for (int j = 0; j < classCount; ++j) {
        total += pClassList[j].gpaEq;
    }

    gpa = total / classCount;
    printf("You semester GPA is %.2f", gpa);
    if (gpa > 3.0) printf(", good job %s!\n", name);
    exit(EXIT_SUCCESS);
}

