#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node {
    int value;
    Node* next;
} Node;

class LinkedList {

    public:

    Node* head;
    int length;

    LinkedList() {
        this->head = NULL;
        this->length = 0;
    }

    Node* createNode(int value) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->value = value;
        node->next = NULL;
        return node;
    }

    void Insert_Beginning(Node* node) {
        node->next = this->head;
        this->head = node;

        this->length++;
    }

    void Insert_End(Node* newNode) {
        Node* node = this->head;

        while (node->next) {
            node = node->next;
        }

        node->next = newNode;
        this->length++;
    }

    void Insert_Middle(Node* newNode, int index) {
        Node* node = this->head;

        // for (int i=1; i<index; i++) {
        for (int i=0; i<index-1; i++) {
            node = node->next;
        }

        newNode->next = node->next;
        node->next = newNode;
        this->length++;
    }

    void Insert(int value, int index) {

        if (index < 0 || index > this->length) {
            cout << "Linked List Out of Bound" << endl;
            return;
        }

        Node* newNode = this->createNode(value);

        if (index == 0) {
            this->Insert_Beginning(newNode);
            return;
        }

        if (index == this->length) {
            this->Insert_End(newNode);
            return;
        }

        this->Insert_Middle(newNode, index);

    }

    void Delete_Beginning() {
        Node* temp = this->head;
        this->head = this->head->next;
        
        free(temp);
        this->length--;
    }
    
    void Delete_End() {
        Node* node = this->head;

        while (node->next->next) {
            node = node->next;
        }

        Node* temp = node->next;
        node->next = NULL;

        free(temp);
        this->length--;
    }
    
    void Delete_Middle(int index) {
        Node* node = this->head;

        // for (int i=1; i<index; i++) {
        for (int i=0; i<index-1; i++) {
            node = node->next;
        }

        Node* temp = node->next;
        node->next = node->next->next;

        free(temp);
        this->length--;
    }
    
    void Delete(int index) {

        if (index < 0 || index >= this->length) {
            cout << "Linked List Out of Bound" << endl;
            return;
        }

        if (index == 0) {
            this->Delete_Beginning();
            return;
        }

        if (index == this->length - 1) {
            this->Delete_End();
            return;
        }

        this->Delete_Middle(index);

    }

    void Display() {
        Node* node = this->head;

        cout << "[ ";
        while (node != NULL) {
            cout << node->value << ", ";
            node = node->next;
        }
        cout << "]" << endl;
    }

};

int main() {

    LinkedList sll;
    
    sll.Display();
    sll.Insert(5, 0);
    sll.Insert(15, 1);
    // sll.Insert(20, 3);
    // sll.Insert(8, 1);
    // sll.Insert(17, 4);
    sll.Display();

    sll.Delete(0);
    sll.Display();

    sll.Delete(0);
    sll.Display();

    // sll.Delete(0);
    // sll.Display();

    sll.Insert(10, 0);
    sll.Display();

    return 0;
}