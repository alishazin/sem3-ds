#include <iostream>
using namespace std;

class Exception {
    public:
    virtual string msg() = 0;
};

class StackOverflow: public Exception {
    public:
    string msg() {
        return "Stack is full.";
    }
};

class StackUnderflow: public Exception {
    public:
    string msg() {
        return "Stack is empty.";
    }
};

class StackEmpty: public Exception {
    public:
    string msg() {
        return "Stack is empty.";
    }
};

class BaseStack {
    public:
    virtual void display() = 0;
};

template <class DType = int> class Stack: public BaseStack {

    int _size;
    int top;
    DType *array;

    public:

        Stack(int _size) {
            this->_size = _size;
            this->top = -1;

            this->array = new DType[_size];
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

        int getTop() {
            return this->top;
        }   

        void push(DType item) {
            
            if (this->isFull()) {
                throw StackOverflow();
            } 

            this->top++;
            this->array[this->top] = item;
        }

        DType pop() {
            
            if (this->isEmpty()) {
                throw StackUnderflow();
            }
            
            this->top--;
            return this->array[this->top + 1];
        }

        void display() {
            
            if (this->isEmpty()) {
                // throw StackEmpty();
                cout << "Empty Stack";
                return;
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

        DType peek() {

            if (this->isEmpty()) {
                throw StackEmpty();
            }
            
            return this->array[this->top];
        }

};

ostream& operator<<(ostream &out, BaseStack &obj) {
    obj.display();
    return out;
}