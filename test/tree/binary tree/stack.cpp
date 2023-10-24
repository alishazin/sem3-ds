#include <iostream>
using namespace std;

class StackException {
    public:
    virtual string msg() = 0;
};

class StackUnderflow: public StackException {
    public:
    string msg() {
        return "Stack is empty.";
    }
};

class StackEmpty: public StackException {
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

    int top;
    DType *array;

    public:

        Stack() {
            this->top = -1;
            this->array = NULL;
        }

        int isEmpty() {
            if (this->top == -1) return 1;
            return 0;
        }        

        int length() {
            return this->top + 1;
        }     

        void resizeStack(int newSize) {

            DType *newArr = new DType[newSize];
            
            for (int i=0; i<newSize; i++) {
                if (i < this->length()) {
                    newArr[i] = this->array[i];
                } else {
                    break;
                }
            }

            if (this->array != NULL) {
                delete this->array;
            }
            this->array = newArr;
            
        }

        void push(DType item) {

            this->resizeStack(this->length() + 1);
            
            this->top++;
            this->array[this->top] = item;
        }

        DType pop() {
            
            if (this->isEmpty()) {
                throw StackUnderflow();
            }
            
            DType returnItem = this->array[this->top];

            this->resizeStack(this->length() - 1);

            this->top--;
            return returnItem;
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
            cout << "Length = " << this->top + 1 << endl << endl; 
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