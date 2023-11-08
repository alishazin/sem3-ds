#include <iostream>
using namespace std;

class Array {

    public:

    int *arr;
    int size;
    int length;

    Array(int size) {

        this->size = size;
        this->arr = (int*) malloc(size * sizeof(int));
        this->length = 0;

    }

    void Insert(int item, int index) {

        if (this->length == this->size) {
            cout << "Array Overflow" << endl;
            return;
        };

        if (index > this->length || index < 0) {
            cout << "Array Out of Bound" << endl;
            return;
        }

        for (int i=this->length-1; i>=index; i--) {
            this->arr[i + 1] = this->arr[i];
        }

        this->arr[index] = item;
        this->length++;

    }

    void Delete(int index) {

        if (index >= this->length || index < 0) {
            cout << "Array Out of Bound" << endl;
            return;
        }

        for (int i=index; i<this->length-1; i++) {
            this->arr[i] = this->arr[i+1];
        }

        this->length--;

    }

    void Display() {

        cout << "[";
        for (int i=0; i<this->length; i++) {
            cout << this->arr[i] << ", ";
        }
        cout << "] size = " << this->size << endl;

    }

};

int main() {

    Array arr(5);

    arr.Insert(10, 0);
    arr.Insert(20, 1);
    arr.Insert(30, 1);
    arr.Insert(40, 0);
    arr.Insert(70, 4);

    arr.Display();

    arr.Delete(4);
    arr.Delete(1);

    arr.Display();

    return 0;
}