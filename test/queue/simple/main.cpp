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
front = 1, rear = 3    ifFull() = if rear = size - 1  
*/

class QueueException {
    public:
    virtual string msg() = 0;
};

class QueueOverflow: public QueueException {
    public:
    string msg() {
        return "Queue is full.";
    }
};

class QueueUnderflow: public QueueException {
    public:
    string msg() {
        return "Queue is empty.";
    }
};

class QueueEmpty: public QueueException {
    public:
    string msg() {
        return "Queue is empty.";
    }
};

class Queue {

    int *arr;
    int _size;
    int _front;
    int _rear;

    public:

    Queue(int size) {
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
        if (this->_rear == this->_size - 1 || this->_front == this->_size) return 1;
        return 0;
    }

    void enqueue(int item) {
        if (this->isFull()) {
            throw QueueOverflow();
        }

        if (this->isEmpty()) this->_rear = this->_front;
        else this->_rear++;

        this->arr[this->_rear] = item;
    }
    
    int dequeue() {
        if (this->isEmpty()) {
            throw QueueUnderflow();
        }
        
        int poppedItem = this->arr[this->_front];
        this->_front++;
        if (this->_front > this->_rear) {
            this->_rear = -1;
        }

        return poppedItem;
    }

    int length() {
        return this->_rear - this->_front + 1;
    }

    int front() {
        if (this->isEmpty()) {
            throw QueueUnderflow();
        }
        return this->arr[this->_front];
    }

    int rear() {
        if (this->isEmpty()) {
            throw QueueUnderflow();
        }
        return this->arr[this->_rear];
    }

    void display() {

        if (this->isEmpty()) {
            cout << "Empty Queue" << endl;
            return;
        }

        cout << "[";
        for (int i=this->_front; i<=this->_rear; i++) {
            cout << this->arr[i];
            if (i != this->_rear) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    void blueprint() {

        if (this->isEmpty()) {
            cout << "Empty Queue" << endl;
            return;
        }

        for (int i=0; i<this->_size; i++) {
            cout << i << " | ";
            if (i < this->_front) {
                cout << this->arr[i];
            } else if (i == this->_front && i == this->_rear) {
                cout << this->arr[i] << " <- FRONT <- REAR";
            } else if (i == this->_front) {
                cout << this->arr[i] << " <- FRONT";
            } else if (i < this->_rear) {
                cout << this->arr[i];
            } else if (i == this->_rear) {
                cout << this->arr[i] << " <- REAR";
            } else if (i > this->_rear) {
                cout << "GARBAGE";
            }
            cout << endl;
        }

    }

};

int main() {

    Queue q(4);

    q.enqueue(10);
    q.enqueue(20);
    q.display();
    q.blueprint();

    cout << q.dequeue() << endl;
    q.display();
    q.blueprint();

    cout << q.dequeue() << endl;
    q.display();
    q.blueprint();
    
    q.enqueue(100);
    q.display();
    q.blueprint();

    q.enqueue(200);
    q.display();
    q.blueprint();

    /*
    In a normal queue, after a bit of insertion and deletion, there will 
    be non-usable empty space.
    */

    return 0;
}