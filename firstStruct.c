#include <stdio.h>
#include <string.h>
#include "structs.h"

int structMain() {
    struct student lucas;
    puts("What is your first name?");
    fgets(lucas.firstName, 20, stdin);
    strtok(lucas.firstName, "\n");

    puts("What is your last name?");
    fgets(lucas.lastName, 20, stdin);
    strtok(lucas.lastName, "\n");

    printf("Hi %s %s, how old are you?\n", lucas.firstName, lucas.lastName);
    scanf("%d", &lucas.age);

    puts("What is your GPA?");
    scanf("%lf", &lucas.GPA);

    printf("\nHere is your profile:\nName:\t%s %s\nAge:\t%d\nGPA:\t%lf\n", lucas.firstName, lucas.lastName,
           lucas.age, lucas.GPA);
    return 0;
}