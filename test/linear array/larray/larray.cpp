#include <iostream>
using namespace std;

class ArrayOverflow {
    public:
    string msg = "Array Overflow!";
};

class ArrayOutOfBound {
    public:
    string msg = "Array out of bound";
};

class LinearArray {

    int size;
    int *arr;
    int n;

    public:

    LinearArray() {
        this->size = 0;
        this->arr = new int[0];
        this->n = 0;
    }

    LinearArray(int size) {
        this->size = size;
        this->arr = new int[size];
        this->n = 0;
    }

    int getSize() {
        return this->size;
    }

    int getLength() {
        return this->n;
    }

    int get(int index) {
        if (index < this->n) {
            return this->arr[index];
        } else {
            throw ArrayOutOfBound();
        }
    }

    void set(int index, int item) {
        if (index < this->n) {
            this->arr[index] = item;
        } else {
            throw ArrayOutOfBound();
        }
    }

    void insert(int index, int item) {
        if (this->n == this->size) {
            throw ArrayOverflow();
        }

        if (index > this->n || index < 0) {
            throw "Array out of bound";
        }

        for (int i=n-1; i>= index; i--) {
            this->arr[i + 1] = this->arr[i];
        }
        this->arr[index] = item;
        this->n++;
    }
    
    void insert(int index, int item, bool dynamic) {
        if (dynamic && this->size == this->n) {
            this->resize(this->size + 1);
        } 
        this->insert(index, item);
    }

    void append(int item) {
        this->insert(this->n, item);
    }

    void append(int item, bool dynamic) {
        if (dynamic && this->size == this->n) {
            this->resize(this->size + 1);
        } 
        this->append(item);
    }

    void display() {
        cout << endl;
        cout << "[";
        for (int i=0; i<n; i++) {
            if (i == n - 1) cout << arr[i];
            else cout << arr[i] << ", ";
        }
        cout << "] Size = " << size;
    }

    void collapse() {
        this->resize(this->n);
    }

    int remove(int index) {
        int intRemoved;

        if (index > this->n - 1 || index < 0) {
           throw ArrayOutOfBound();
        }

        intRemoved = this->arr[index];
        for (int i=index; i<this->n-1; i++) {
            this->arr[i] = this->arr[i + 1];
        }
        this->n--;

        return intRemoved;
    }

    int search(int item) {
        for (int i=0; i<this->n; i++) {
            if (this->arr[i] == item) {
                return i;
            }
        }
        return -1;
    }

    void reverse() {
        int temp;
        for (int i=0; i<(int) (this->n/2); i++) {
            temp = this->arr[i];
            this->arr[i] = this->arr[this->n - (i + 1)];
            this->arr[this->n - (i + 1)] = temp;
        }
    }

    void sort() {
        int i, j, temp, swapped_flag = 0;
    
        for (i=0; i<this->n-1; i++) {

            for (j=0; j<this->n-i-1; j++) {

                if (this->arr[j] > this->arr[j+1]) {
                    temp = this->arr[j];
                    this->arr[j] = this->arr[j+1];
                    this->arr[j+1] = temp;
                    swapped_flag = 1;
                }

            }

            // If no swaps in one traversal.
            if (swapped_flag == 0) break;

        }
    }

    void resize(int newSize) {
        int *newArr = new int[newSize];

        for (int i=0; i<newSize; i++) {
            if (i < n) {
                newArr[i] = this->arr[i];
            } else {
                break;
            }
        }

        this->arr = newArr;
        this->size = newSize;

        if (newSize < n) {
            this->n = newSize;
        }
    }

};

ostream& operator<<(ostream &out, LinearArray obj) {
    obj.display();
    return out;
}
