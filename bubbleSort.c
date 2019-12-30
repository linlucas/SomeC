#include <stdio.h>
#include <stdlib.h>

int bubbleSortMain() {
    int arrLen, temp;
    char* end;
    char line[256];
    _Bool isSorted = 0;

    puts("How many items are in the array?");
    fgets(line, sizeof(line), stdin);
    arrLen = (int) strtol(line, &end, 10);
    int arr[arrLen];

    for (int i = 0; i < arrLen; ++i) {
        printf("Please enter your number for item #%d\n", i + 1);
        scanf("%d", &arr[i]);
    }

    while (!isSorted) {
        isSorted = 1;
        for (int i = 0; i < arrLen - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
        for (int k = 0; k < arrLen; ++k) {
            for (int i = k + 1; i < arrLen; ++i) {
                if (arr[k] > arr[i]) {
                    isSorted = 0;
                }
            }
        }
    }

    puts("Sorted List:");
    for (int j = 0; j < arrLen; ++j) {
        printf("item #%d: %d\n", j + 1, arr[j]);
    }
    return 0;
}