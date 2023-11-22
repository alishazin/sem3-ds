#include <iostream>
#include <cstdlib>
using namespace std;

class Queue {

    public:

    int* arr;
    int size;
    int front;
    int rear;

    Queue(int size) {
        this->arr = (int*) malloc(sizeof(int) * size);
        this->size = size;
        this->rear = -1;
        this->front = 0;
    }

    int isEmpty() {
        return this->rear == -1;
    }

    int isFull() {
        return this->rear == this->size - 1;
    }

    void Enqueue(int value) {

        if (this->isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }

        this->rear++;
        this->arr[this->rear] = value;

    }

    void Dequeue() {

        if (this->isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }

        cout << "Popped Item: " << this->arr[this->front] << endl;
        this->front++;

        if (this->front > this->rear) {
            this->rear = -1;
            this->front = 0;
        }

    }

    void Peek() {

        if (this->isEmpty()) {
            cout << "Queue Empty" << endl;
            return;
        }

        cout << "Front Element: " << this->arr[this->front] << endl;

    }

    void Display() {

        if (this->isEmpty()) {
            cout << "Queue Empty" << endl;
            return;
        }

        cout << "[ ";

        for (int i=0; i<this->front; i++) {
            cout << "_, ";
        }

        for (int i=this->front; i<=this->rear; i++) {
            cout << this->arr[i] << ", ";
        }

        for (int i=this->rear+1; i<this->size; i++) {
            cout << "_, ";
        }

        cout << "]" << endl;
        cout << "FRONT : " << this->arr[this->front] << endl;
        cout << "REAR : " << this->arr[this->rear] << endl;

    }

};

int main() {

    Queue q(4);

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    q.Display();

    q.Dequeue();
    q.Display();

    q.Dequeue();
    q.Display();

    q.Dequeue();
    q.Display();

    q.Enqueue(100);
    q.Display();
    q.Peek();

    return 0;
}