#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node {
    int value;
    Node* next;
    Node* prev;
} Node;

class LinkedList {

    public:

    Node* head;
    Node* end;
    int length;

    LinkedList() {
        this->head = NULL;
        this->end = NULL;
        this->length = 0;
    }

    Node* createNode(int value) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->value = value;
        node->next = NULL;
        node->prev = NULL;
        return node;
    }

    void Insert_Beginning(Node* node) {
        node->next = this->head;
        this->head = node;

        if (node->next == NULL) {
            // if first
            this->end = node;
        } else {
            node->next->prev = node;
        }

        this->length++;
    }

    void Insert_End(Node* newNode) {
        Node* node = this->head;

        while (node->next) {
            node = node->next;
        }

        this->end = newNode;
        newNode->prev = node;
        node->next = newNode;
        this->length++;
    }

    void Insert_Middle(Node* newNode, int index) {
        Node* node = this->head;

        // for (int i=1; i<index; i++) {
        for (int i=0; i<index; i++) {
            node = node->next;
        }

        newNode->next = node;
        newNode->prev = node->prev;
        node->prev->next = newNode;
        node->prev = newNode;
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
        this->head->prev = NULL;

        if (this->head == NULL) {
            // if all deleted
            this->end = this->head;
        } else {
            this->head->next->prev = this->head;
        }
        
        free(temp);
        this->length--;
    }
    
    void Delete_End() {
        Node* node = this->head;

        while (node->next) {
            node = node->next;
        }

        Node* temp = node;

        node->prev->next = NULL;
        this->end = node->prev;
        
        free(temp);
        this->length--;
    }
    
    void Delete_Middle(int index) {
        Node* node = this->head;

        for (int i=0; i<index; i++) {
            node = node->next;
        }

        Node* temp = node;

        node->prev->next = node->next;
        node->next->prev = node->prev;

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

    void DisplayReverse() {
        Node* node = this->end;

        cout << "[ ";
        while (node != NULL) {
            cout << node->value << ", ";
            node = node->prev;
        }
        cout << "]" << endl;
    }

};

int main() {

    LinkedList dll;
    
    dll.Display();
    dll.Insert(5, 0);
    dll.Insert(15, 1);
    dll.Insert(20, 2);
    dll.Insert(8, 1);
    dll.Insert(1, 0);
    dll.Display();
    dll.DisplayReverse();

    dll.Delete(0);
    dll.Display();
    dll.DisplayReverse();
    
    dll.Delete(3);
    dll.Display();
    dll.DisplayReverse();
    
    dll.Delete(1);
    dll.Display();
    dll.DisplayReverse();

    return 0;
}