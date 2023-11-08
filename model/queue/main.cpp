#include <iostream>
using namespace std;

class Queue {

    int size;
    int *arr;
    int front;
    int rear;

    public:

    Queue(int size) {
        this->size = size;
        this->arr = (int*) malloc(sizeof(int) * size);
        this->front = 0;
        this->rear = -1;
    }

    int isFull() {
        if (this->rear == this->size - 1) return 1;
        return 0;
    }

    int isEmpty() {
        if (this->rear == -1) return 1;
        return 0;
    }

    void Enqueue(int item) {

        if (this->isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }

        this->rear++;
        this->arr[this->rear] = item;

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

        cout << "[";

        for (int i=0; i<this->front; i++) {
            cout << "_ ,";
        }

        for (int i=this->front; i<=this->rear; i++) {
            cout << this->arr[i] << ", ";
        }

        for (int i=this->rear+1; i<this->size; i++) {
            cout << "_ ,";
        }

        cout << "]" << endl;
        cout << "FRONT: " << this->front << endl;
        cout << "REAR: " << this->rear << endl;

    }

};

int main() {
    
    Queue q(5);

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);


    q.Display();

    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();

    q.Display();

    q.Enqueue(10);

    q.Display();
    q.Peek();

    return 0;
}