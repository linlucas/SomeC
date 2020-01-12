#include <stdio.h>
#include <stdlib.h>

int fileMain(int argc, char *argv[]) {
    FILE *pFile;

    if (argc != 2) {
        puts("The command is not correctly formatted\n");
        exit(EXIT_FAILURE);
    }

    if ((pFile = fopen(argv[1], "w")) == NULL) {
        fprintf(stderr, "%s cannot be opened", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("%s is now open\n", argv[1]);
    fprintf(pFile, "Hello there its me lucas\n");

    if (ferror(pFile) || feof(pFile)) {
        printf("some error occurred\n");
    }

    fclose(pFile);
    fclose(stdin);
    return EXIT_SUCCESS;
}