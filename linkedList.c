#include <stdio.h>

struct node {
    int value;
    struct node *nextNode;
};

int linkedListMain() {
    struct node *firstPtr;
    struct node n1, n2, n3;

    firstPtr = &n1;
    n1.nextNode = &n2;
    n2.nextNode = &n3;
    n3.nextNode = 0;

    n1.value = 300;
    n2.value = 200;
    n3.value =100;

    while (firstPtr != 0) {
        printf("%d\n", firstPtr->value);
        firstPtr = firstPtr->nextNode;
    }
    return 0;
}