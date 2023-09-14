#include <iostream>
#include <cstdlib>
using namespace std;

class Queue {

    int _size;
    int _rear;
    int _front;
    int *arr;

    public:

    Queue(int size) {
        this->_size = size;
        this->arr = (int*) malloc(size * sizeof(int));
        this->_rear = -1;
        this->_front = 0;
    }

    int isFull() {
        if (this->_rear == this->_size - 1) return 1;
        return 0;
    }

    int isEmpty() {
        if (this->_rear == -1) return 1;
        return 0;
    }

    void Enqueue(int item) {
        if (this->isFull()) {
            cout << "Queue Overflow" << endl;
        } else {
            this->_rear++;
            this->arr[this->_rear] = item;
        }
    }

    void Dequeue() {
        if (this->isEmpty()) {
            cout << "Queue Underflow" << endl;
        } else {
            int poppedItem = this->arr[this->_front];
            cout << "Popped Item: " << poppedItem << endl; 
            this->_front++;
            if (this->isEmpty() || this->_front > this->_rear) {
                this->_rear = -1;
                this->_front = 0;
            }
        }
    }

    void Display() {
        cout << "[";
        for (int i=0; i<this->_size; i++) {
            if (i < this->_front) {
                cout << "_"; 
            } else if (i <= this->_rear) {
                cout << this->arr[i]; 
            } else {
                cout << "_";
            }

            if (i != this->_size - 1){
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    void Peek() {
        if (this->isEmpty()) {
            cout << "Stack Underflow" << endl;
        } else {
            cout << "Front Element: " << this->arr[this->_front] << endl;
        }
    }

};

int main() {

    int temp1, choice, size;
    
    cout << "Enter size of Queue: ";
    cin >> size;

    Queue q(size);

    while (1) {

        cout << "------ Queue Data Structure ------" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {

            cout << "Enter item to insert: ";
            cin >> temp1;

            q.Enqueue(temp1);

        } else if (choice == 2) {

            q.Dequeue();
        
        } else if (choice == 3) {

            q.Peek();
            
        } else if (choice == 4) {
            
            q.Display();

        } else if (choice == 5) {
            
            cout << "\n--------- Author ----------------" << endl;
    		cout << "Ali Izzath Shazin" << endl;
    		cout << "220071601028" << endl;
    		cout << "B. Tech CSE A" << endl;
            break;
           
        } else {

            cout << "Invalid Option" << endl;
            
        }

        cout << endl;
    }

    return 0;
}