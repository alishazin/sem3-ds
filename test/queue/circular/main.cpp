#include <iostream>
using namespace std;

/*
Front - Rear
size = 4

  0   1   2   3
|   |   |   |   |
front = -1, rear = -1  ifEmpty() = if rear = -1
rear = -1 front = prev value

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

  0   1   2   3
| 4 | 7 | 6 | 5 |
front = 2, rear = 1     

  0   1   2   3
| 4 | 7 | 6 | 5 |
front = 0, rear = 3    

if front > rear:
    front - rear == 1
else if front < rear:
    rear - front = size - 1
else:
    length is 1 so not full

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
        this->_front = -1;
        this->_rear = -1;
        arr = (int*) malloc(size * sizeof(int));
    }

    int isEmpty() {
        if (this->_rear == -1) return 1;
        return 0;
    }

    int isFull() {
        if (this->_front > this->_rear && this->_front - this->_rear == 1) return 1;
        if (this->_front < this->_rear && this->_rear - this->_front == this->_size - 1) return 1;
        return 0;
    }

    void push(int item) {
        if (isFull()) {
            throw CircularQueueOverflow();
        }

        if (isEmpty()) {
            if (this->_rear != this->_front) {
                this->_rear = this->_front;
            } else {
                this->_rear = 0;
                this->_front = 0;
            }
        } else {
            this->_rear = (this->_rear + 1) % this->_size;
        }

        this->arr[this->_rear] = item;
    }
    
    void pop() {
        if (isEmpty()) {
            throw CircularQueueUnderflow();
        }

        this->_front = (this->_front + 1) % this->_size;

        if (this->_rear == this->_front) {
            this->_rear = -1;
        }
    }

    int length() {
        return this->_rear - this->_front + 1;
    }

    int front() {
        if (isEmpty()) {
            throw CircularQueueUnderflow();
        }
        return this->arr[this->_front];
    }

    int rear() {
        if (isEmpty()) {
            throw CircularQueueUnderflow();
        }
        return this->arr[this->_rear];
    }

    void display() {

        if (isEmpty()) {
            cout << "Empty Queue" << endl;
            return;
        }

        cout << "[";
        for (int i=0; i<this->_size; i++) {
            cout << this->arr[i] << ", ";
            // if (i != this->_rear) {
            //     cout << ", ";
            // }
        }
        cout << "]" << endl;
    }

    void blueprint() {

        if (isEmpty()) {
            cout << "Empty Queue" << endl;
            return;
        }

        for (int i=0; i<this->_size; i++) {
            cout << i << " | ";
            if (i < this->_front) {
                cout << this->arr[i];
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

    CircularQueue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    cout << q.front() << endl;
    cout << q.rear() << endl;

    q.pop();
    q.pop();
    // q.pop();
    // q.pop();
    q.display();
    cout << q.front() << endl;
    cout << q.rear() << endl;

    // q.push(50);
    // q.display();
    // cout << q.front() << endl;
    // cout << q.rear() << endl;
    
    // q.push(60);
    // q.display();
    // cout << q.front() << endl;
    // cout << q.rear() << endl;


    return 0;
}