#include <iostream>
#include <cstdlib>
using namespace std;

class Stack {

    public:

    int* arr;
    int top;
    int size;

    Stack(int size) {

        this->arr = (int*) malloc(sizeof(int));
        this->top = -1;
        this->size = size;

    }

    int isEmpty() {
        return this->top == -1;
    }

    int isFull() {
        return this->top == this->size - 1;
    }

    void Push(int value) {

        if (this->isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }

        this->top++;
        this->arr[this->top] = value;

    }

    int Pop() {

        if (this->isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int deletedItem = this->arr[this->top];
        this->top--;
        return deletedItem;

    }

    int Peek() {

        if (this->isEmpty()) {
            cout << "Stack Empty" << endl;
            return -1;
        }

        return this->arr[this->top];

    }

    void Display() {

        if (this->isEmpty()) {
            cout << "Stack Empty" << endl;
            return;
        }

        cout << this->arr[this->top] << " <- Top" << endl;
        for (int i=this->top-1; i>=0; i--) {
            cout << this->arr[i] << endl;
        }
        cout << "Size = " << this->size;

    }
 
};

int main() {

    Stack s(4);

    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Display();
    cout << endl;

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    s.Display();
    cout << endl;

    cout << s.Peek() << endl;
    
    return 0;
}