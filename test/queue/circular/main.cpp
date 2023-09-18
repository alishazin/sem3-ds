#include <iostream>
using namespace std;

/*
Front - Rear
size = 4

  0   1   2   3
|   |   |   |   |
front = 0, rear = -1   ifEmpty() = if rear = -1

  0   1   2   3
| 8 |   |   |   |
front = 0, rear = 0  

  0   1   2   3
| 8 | 7 |   |   |
front = 0, rear = 1  

  0   1   2   3
| 8 | 7 | 6 |   |
front = 0, rear = 2  

  0   1   2   3
|   | 7 | 6 |   |
front = 1, rear = 2  

  0   1   2   3
|   | 7 | 6 | 5 |
front = 1, rear = 3

  0   1   2   3
| 4 | 7 | 6 | 5 |
front = 1, rear = 0

ifFull() conditions:

  0   1   2   3
| 1 | 2 | 3 | 4 |
front = 0, rear = 3

if (front == 0 && rear == size - 1)

  0   1   2   3
| 4 | 1 | 2 | 3 |
front = 1, rear = 0

  0   1   2   3
| 3 | 4 | 1 | 2 |
front = 2, rear = 1

  0   1   2   3
|   | 1 | 2 |   |
front = 1, rear = 2 (wont match)

if (front != 0 && rear = front - 1)

ifEmpty() condition: 
if (rear == -1)

*/

class CircularQueueException {
    public:
    virtual string msg() = 0;
};

class CircularQueueOverflow: public CircularQueueException {
    public:
    string msg() {
        return "Queue is full.";
    }
};

class CircularQueueUnderflow: public CircularQueueException {
    public:
    string msg() {
        return "Queue is empty.";
    }
};

class CircularQueueEmpty: public CircularQueueException {
    public:
    string msg() {
        return "Queue is empty.";
    }
};

class CircularQueue {

    int *arr;
    int _size;
    int _front;
    int _rear;

    public:

    CircularQueue(int size) {
        this->_size = size;
        this->_front = 0;
        this->_rear = -1;
        arr = (int*) malloc(size * sizeof(int));
    }

    int isEmpty() {
        if (this->_rear == -1) return 1;
        return 0;
    }

    int isFull() {
        if ((this->_front == 0 && this->_rear == this->_size - 1 ) || (this->_front != 0 && this->_rear == this->_front - 1)) return 1;
        return 0;
    }

    void enqueue(int item) {
        if (this->isFull()) {
            throw CircularQueueOverflow();
        }

        if (this->isEmpty()) this->_rear = this->_front;
        else this->_rear = (this->_rear + 1) % this->_size;

        this->arr[this->_rear] = item;
    }
    
    int dequeue() {
        if (this->isEmpty()) {
            throw CircularQueueUnderflow();
        }
        
        int poppedItem = this->arr[this->_front];
        if (this->_front == this->_rear) {
            this->_rear = -1;
        }
        this->_front = (this->_front + 1)%this->_size;

        return poppedItem;
    }

    int length() {
        return this->_rear - this->_front + 1;
    }

    int front() {
        if (this->isEmpty()) {
            throw CircularQueueUnderflow();
        }
        return this->arr[this->_front];
    }

    int rear() {
        if (this->isEmpty()) {
            throw CircularQueueUnderflow();
        }
        return this->arr[this->_rear];
    }

    void display() {
        if (this->isEmpty()) {
            cout << "[]" << endl;
            return;
        }

        cout << "[";
        int i = this->_front;
        while (i != this->_rear) {
            cout << this->arr[i];
            cout << ", ";
            i = (i + 1)%this->_size;
        }
        cout << this->arr[i];
        cout << "]" << endl;
    }

    void blueprint() {

        for (int i=0; i<this->_size; i++) {
            
            cout << i << " | ";

            if (this->_rear == -1) {
                cout << "GARBAGE";
            } else if (this->_front <= this->_rear && ( i < this->_front || i > this->_rear)) {
                cout << "GARBAGE";
            } else if (this->_front > this->_rear && ( i < this->_front && i > this->_rear)) {
                cout << "GARBAGE";
            } else {
                cout << this->arr[i]; 
            }
            
            if (i == this->_rear) {
                cout << " <- REAR";
            }
            if (i == this->_front) {
                cout << " <- FRONT";
            }
            cout << endl;
        }

    }

};

int main() {

    CircularQueue q(4);
    q.display();
    q.blueprint();

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();
    q.blueprint();

    cout << q.dequeue() << endl;
    q.display();
    q.blueprint();

    q.enqueue(50);
    q.display();
    q.blueprint();

    cout << q.dequeue() << endl;
    q.display();
    q.blueprint();

    q.enqueue(60);
    q.display();
    q.blueprint();

    cout << q.dequeue() << endl;
    q.display();
    q.blueprint();

    q.enqueue(70);
    q.display();
    q.blueprint();

    cout << q.dequeue() << endl;
    q.display();
    q.blueprint();

    q.enqueue(80);
    q.display();
    q.blueprint();

    cout << q.dequeue() << endl;
    q.display();
    q.blueprint();

    q.enqueue(90);
    q.display();
    q.blueprint();

    cout << q.dequeue() << endl;
    q.display();
    q.blueprint();

    q.enqueue(100);
    q.display();
    q.blueprint();

    cout << q.dequeue() << endl;
    q.display();
    q.blueprint();

    cout << q.dequeue() << endl;
    q.display();
    q.blueprint();

    cout << q.dequeue() << endl;
    q.display();
    q.blueprint();

    cout << q.dequeue() << endl;
    q.display();
    q.blueprint();

    q.enqueue(110);
    q.display();
    q.blueprint();

    q.enqueue(120);
    q.display();
    q.blueprint();

    cout << q.dequeue() << endl;
    q.display();
    q.blueprint();
    
    cout << q.dequeue() << endl;
    q.display();
    q.blueprint();
    
    q.enqueue(130);
    q.display();
    q.blueprint();

    return 0;
}