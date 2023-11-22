#include <iostream>
#include <cstdlib>
using namespace std;

class Array {

    public:

    int *arr;
    int size;
    int length;

    Array(int size) {
        this->arr = (int*) malloc(sizeof(int) * size);
        this->size = size;
        this->length = 0;
    }

    void Insert(int value, int index) {

        if (this->length == this->size) {
            cout << "Array Overflow" << endl;
            return;
        }

        if (index > this->length || index < 0) {
            cout << "Array Out of bound" << endl;
            return;
        }

        for (int i=this->length-1; i>=index; i--) {
            this->arr[i + 1] = this->arr[i];
        }

        this->arr[index] = value;
        this->length++;

    }

    void Delete(int index) {

        if (this->length == 0) {
            cout << "Array Underflow" << endl;
            return;
        }

        if (index >= this->length || index < 0) {
            cout << "Array Out of bound" << endl;
            return;
        }

        for (int i=index; i<this->length; i++) {
            this->arr[i] = this->arr[i + 1];
        }

        this->length--;

    }

    void Display() {
        
        cout << "[ ";
        for (int i=0; i<this->length; i++) {
            cout << this->arr[i] << ", ";
        }
        cout << "] Size = " << this->size << endl;

    }

};

int main() {

    Array arr(5);

    arr.Insert(10, 0);
    arr.Insert(20, 1);
    arr.Insert(30, 1);
    arr.Insert(40, 0);
    arr.Insert(50, 0);
    arr.Display();
    arr.Delete(0);
    arr.Delete(0);
    arr.Delete(0);
    arr.Delete(0);
    arr.Delete(0);
    arr.Display();

    return 0;
}