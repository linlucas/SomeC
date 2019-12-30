#include <stdio.h>

#define TRUE 1
#define FALSE 0

int efficientBubbleMain() {
    int arrLen;
    int madeSwap, temp;

    puts("How many items are in the array?");
    scanf("%d", &arrLen);
    int arr[arrLen];

    for (int i = 0; i < arrLen; ++i) {
        printf("Please enter your number for item #%d\n", i + 1);
        scanf("%d", &arr[i]);
    }

    // If bubbleSort goes a complete pass over the array without swapping anything,
    // we will know that the array is sorted.
    while (1) {
        madeSwap = FALSE;
        for (int i = 0; i < arrLen - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                madeSwap = TRUE;
            }
        }
        if (!madeSwap) {
            break;
        }
    }

    puts("Sorted List:");
    for (int j = 0; j < arrLen; ++j) {
        printf("item #%d: %d\n", j + 1, arr[j]);
    }
    return 0;
}