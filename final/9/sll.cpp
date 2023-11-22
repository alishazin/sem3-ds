#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node {
    int value;
    Node* next;
} Node;

class Queue {

    public:

    Node* head;
    Node* end;

    Queue() {
        this->head = NULL;
        this->end = NULL;
    }

    Node* createNode(int value) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->value = value;
        node->next = NULL;
        return node;
    }

    int isEmpty() {
        return this->head == NULL;
    }

    void Enqueue(int value) {
        Node* newNode = this->createNode(value);

        if (this->isEmpty()) {
            this->head = newNode;
            this->end = newNode;
        } else {
            this->end->next = newNode;
            this->end = newNode;
        }
    }

    void Dequeue() {

        if (this->isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }

        Node* temp = this->head;

        if (this->head->next == NULL) {
            // if empty
            this->head = NULL;
            this->end = NULL;
        } else {
            // if not empty
            this->head = this->head->next;
        }

        free(temp);
    }

    void Peek() {

        if (this->isEmpty()) {
            cout << "Queue Empty" << endl;
            return;
        }

        cout << "Front Item: " << this->head->value << endl;

    }

    void Display() {

        if (this->isEmpty()) {
            cout << "Queue Empty" << endl;
            return;
        }

        Node* node = this->head;
        cout << "[ ";
        while (node) {
            cout << node->value << ", ";
            node = node->next;
        }
        cout << "]" << endl;
        cout << "FRONT = " << this->head->value << endl;
        cout << "REAR = " << this->end->value << endl;

    }

};

int main() {

    Queue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    
    q.Display();

    q.Dequeue();
    q.Dequeue();

    q.Display();
    q.Peek();

    return 0;
}