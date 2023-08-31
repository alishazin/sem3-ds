#include <iostream>
using namespace std;

class Exception {
    public:
    virtual string msg() = 0;
};

class StackOverflow: public Exception {
    public:
    string msg() {
        return "Stack overflow!.";
    }
};

class StackUnderflow: public Exception {
    public:
    string msg() {
        return "Stack underflow!";
    }
};

class StackEmpty: public Exception {
    public:
    string msg() {
        return "Stack is empty.";
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

ostream& operator<<(ostream &out, Stack &obj) {
    obj.display();
    return out;
}

int main() {

    int size, choice, temp;

    cout << "Enter size of the stack: ";
    cin >> size;

    Stack stack = Stack(size);

    while (true) {

        cout << "---------- Stack Operations ----------" << endl;
        cout << "1. Push." << endl;
        cout << "2. Pop." << endl;
        cout << "3. Peek." << endl;
        cout << "4. Display." << endl;
        cout << "5. Exit." << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {

            cout << "Enter element to push: ";
            cin >> temp;

            try {
                stack.push(temp);
            } catch(Exception &e) {
                cout << endl << e.msg() << endl << endl;
            }

        } else if (choice == 2) {

            try {
                int temp = stack.pop();
                cout << endl << "Popped element: " << temp << endl << endl; 
            } catch(Exception &e) {
                cout << endl << e.msg() << endl << endl;
            }

        } else if (choice == 3) {

            try {
                int temp = stack.peek();
                cout << endl << "Top element: " << temp << endl << endl; 
            } catch(Exception &e) {
                cout << endl << e.msg() << endl << endl;
            }

        } else if (choice == 4) {

            try {
                cout << stack << endl;
            } catch(Exception &e) {
                cout << endl << e.msg() << endl << endl;
            }
            
        } else if (choice == 5) {

            cout << "Exiting..." << endl;

            cout << endl << "------ Author ------" << endl;
            cout << "Ali Izzath Shazin K" << endl;
            cout << "220071601028" << endl;
            cout << "B.Tech CSE A" << endl;
            break;

        } else {
            cout << "Invalid Option." << endl;
        }

    }


    return 0;
}