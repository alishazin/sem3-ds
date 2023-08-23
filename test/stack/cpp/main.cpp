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

int main() {

    Stack<> stack = Stack<>(5); // By default, its int
    // Stack<int> stack = Stack<int>(5);
    // Stack<char> stack = Stack<char>(5);
    // Stack<string> stack = Stack<string>(5);
    
    stack.push(11);
    stack.push(14);
    stack.push(17);
    stack.push(21);
    stack.push(23);

    // stack.push('a');
    // stack.push('b');
    // stack.push('c');
    // stack.push('d');
    // stack.push('e');

    // stack.push("AA");
    // stack.push("BB");
    // stack.push("CC");
    // stack.push("DD");
    // stack.push("EE");

    try {
        stack.push(26);
        // stack.push('f');
        // stack.push("FF");
    } catch(Exception &e) {
        cout << e.msg() << endl;
    } // catch all derived classes from Exception

    stack.display();

    stack.pop();
    cout << stack.pop() << endl;

    cout << stack.peek() << endl;
    cout << stack.size() << endl;

    cout << stack << endl;

    return 0;
}