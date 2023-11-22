#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node {
    int value;
    Node* next;
} Node;

class Stack {

    public:

    Node* head;

    Stack() {
        this->head = NULL;
    }

    Node* createNode(int value) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->next = NULL;
        node->value = value;
        return node;
    }

    int isEmpty() {
        return this->head == NULL;
    }

    void Push(int value) {
        Node* newNode = this->createNode(value);

        newNode->next = this->head;
        this->head = newNode;
    }

    int Pop() {

        if (this->isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int deletedValue = this->head->value;
        Node* temp = this->head;

        this->head = this->head->next;
        free(temp);
        
        return deletedValue;

    }

    int Peek() {

        if (this->isEmpty()) {
            cout << "Stack Empty" << endl;
            return -1;
        }

        return this->head->value;

    }

    void Display() {

        if (this->isEmpty()) {
            cout << "Stack Empty" << endl;
            return;
        }

        cout << this->head->value << " <- Top" << endl;
        
        Node* node = this->head->next;
        while (node) {
            cout << node->value << endl;
            node = node->next;
        }

    }
 
};

int main() {

    Stack s;

    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Display();
    cout << endl;

    cout << s.Pop() << endl << endl;
    cout << s.Pop() << endl << endl;
    cout << s.Pop() << endl << endl;
    
    s.Push(40);
    s.Display();
    cout << endl;

    cout << s.Peek() << endl;
    
    return 0;
}