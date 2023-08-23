#include <iostream>
using namespace std;

class Exception {
    public:
    virtual void msg() = 0;
};

class StackOverflow: public Exception {
    public:
    void msg() {
        cout << "Stack is full." << endl;
    }
};

class StackUnderflow: public Exception {
    public:
    void msg() {
        cout << "Stack is empty." << endl;
    }
};

class StackEmpty: public Exception {
    public:
    void msg() {
        cout << "Stack is empty." << endl;
    }
};

class Stack {

    int _size;
    int top;
    int *array;

    public:

        Stack(int _size) {
            this->_size = _size;
            this->top = -1;

            this->array = new int[_size];
        }

        int isEmpty() {
            if (this->top == -1) return 1;
            return 0;
        }        

        int isFull() {
            if (this->top == this->_size - 1) return 1;
            return 0;
        }  

        int size() {
            return this->_size;
        }      

        void push(int item) {
            
            if (this->isFull()) {
                throw StackOverflow();
            } 

            this->top++;
            this->array[this->top] = item;
        }

        int pop() {
            
            if (this->isEmpty()) {
                throw StackUnderflow();
            }
            
            this->top--;
            return this->array[this->top + 1];
        }

        void display() {
            
            if (this->isEmpty()) {
                throw StackEmpty();
            }

            cout << endl;
            for (int i=this->top; i>-1; i--) {
                if (i == this->top) {
                    cout << this->array[i] << " <-- Top" << endl;
                } else {
                    cout << this->array[i] << endl;
                }
            }
            cout << "Size = " << this->_size << endl << endl; 
        }

        int peek() {

            if (this->isEmpty()) {
                throw StackEmpty();
            }
            
            return this->array[this->top];
        }

};

ostream& operator<<(ostream &out, Stack obj) {
    obj.display();
    return out;
}

int main() {

    Stack stack = Stack(5);
    
    stack.push(11);
    stack.push(14);
    stack.push(17);
    stack.push(21);
    stack.push(23);
    try {
        stack.push(26);
    } catch(Exception &e) {
        cout << "ads" << endl;
        e.msg();
    } // catch all derived classes from Exception

    stack.display();

    stack.pop();
    cout << stack.pop() << endl;

    cout << stack.peek() << endl;
    cout << stack.size() << endl;

    cout << stack << endl;

    return 0;
}