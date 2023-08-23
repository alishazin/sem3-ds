#include <iostream>
using namespace std;

int main() {

    int *a = NULL;

    if (a == NULL) {
        cout << "a Size: " << sizeof(a) << endl;
        cout << "a NULL" << endl;
    } else {
        cout << "a NOT NULL" << endl;
    }

    void *b; // NULL if only explictly said
    if (b == NULL) {
        cout << "b Size: " << sizeof(b) << endl;
        cout << "NULL" << endl;
    } else {
        cout << "b NOT NULL" << endl;
    }

    void *c;
    int num = 10;
    c = &num;

    cout << *(int*)c << endl;

    // int *d = c; // error
    // Why?
    // Unlike c, in c++, we have to typecast the void pointer to the respective dtype.
    // Here, we have to typecast the void pointer to int*

    int *d = (int*)c;
    cout << *(int*)c << endl;

    int *array;
    array = (int*) malloc(3 * sizeof(int));
    // Here we need explicit type-casting

    array[0] = 1;
    array[1] = 2;
    array[2] = 3;

    cout << endl;
    for (int i=0; i<3; i++) cout << array[i] << ", ";

    return 0;
}