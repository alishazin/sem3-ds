#include <stdio.h>
#include <stdlib.h>

int main() {

    int *a = NULL;

    if (a == NULL) {
        printf("\na Size: %d", sizeof(a));
        printf("\na NULL");
    } else {
        printf("\na NOT NULL");
    }

    void *b; // NULL if only explictly said
    if (b == NULL) {
        printf("\nb Size: %d", sizeof(b));
        printf("\nb NULL");
    } else {
        printf("\nb NOT NULL");
    }

    void *c;
    int num = 10;
    c = &num;

    printf("\n%d", *(int*)c);

    int *d = c; // Not error
    // Why?
    // Unlike c++, c does not throw an error for this.

    int *e = (int*)c;
    printf("\n%d", *(int*)e);
    // Althought, if you want to, you can typecast the void pointer before 
    // storing it in a pointer of specific dtype.

    // With malloc() (Example)
    int *array;
    array = malloc(3 * sizeof(int));
    // Here no need of type-casting

    array[0] = 1;
    array[1] = 2;
    array[2] = 3;

    printf("\n");
    for (int i=0; i<3; i++) printf("%d, ", array[i]);

    return 0;
}