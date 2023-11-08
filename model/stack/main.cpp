#include <iostream>
using namespace std;

class Stack {

    int size;
    int top;
    int *arr;

    public:

    Stack(int size) {

        this->size = size;
        this->top = -1;
        this->arr = (int*) malloc(sizeof(int) * size);

    }

    int isEmpty() {
        if (this->top == -1) return 1;
        return 0;
    }

    int isFull() {
        if (this->top == this->size - 1) return 1;
        return 0;
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

        this->top--;
        return this->arr[this->top + 1];

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
        }

        cout << this->arr[this->top] << " <- Top" << endl;
        for (int i=this->top - 1; i>=0; i--) {
            cout << this->arr[i] << endl;
        }

    }

};

int main() {

    Stack stack(5);

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    stack.Display();
    cout << endl;

    // cout << stack.Pop() << endl;
    cout << stack.Peek() << endl << endl;

    stack.Display();
    cout << endl;

    return 0;
}