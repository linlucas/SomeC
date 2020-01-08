#include <stdio.h>
#include <assert.h>

#define NELEMS(a) (int) (sizeof(a)/sizeof(a[0]))

int main() {
    char something[] = "asfsadf";
    printf("%d", NELEMS(something));
}