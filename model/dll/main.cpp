#include <iostream>
using namespace std;

typedef struct Node {
    int value;
    Node* next;
    Node* prev;
} Node;

class LinkedList {

    public:

    Node* Head;
    Node* End;
    int length;

    LinkedList() {
        this->Head = NULL;
        this->End = NULL;
        this->length = 0;
    }

    Node* createNode(int value) {

        Node* node = (Node*) malloc(sizeof(Node));
        node->value = value;
        node->next = NULL;
        node->prev = NULL;

        return node;

    }

    void Insert(int index, int value) {

        if (index > this->length) {
            cout << "Linked List Index Out Of Bound" << endl;
            return;
        }

        Node* newNode = this->createNode(value);

        if (index == 0) {
            newNode->next = this->Head;
            this->Head = newNode;
            
            if (this->Head->next == NULL) {
                this->End = newNode;
            } else {
                newNode->next->prev = newNode;
            }
            this->length++;
            return;
        }

        if (index == this->length) {
            
            this->End->next = newNode;
            newNode->prev = this->End;
            this->End = newNode;
            this->length++;
            return;

        }

        Node* node = this->Head;
        for (int i=0; i<index; i++) {
            node = node->next;
        }

        newNode->prev = node->prev;
        newNode->next = node;
        node->prev->next = newNode;
        node->prev = newNode;
        this->length++;
        return;

    }

    int Delete(int index) {

        if (index > this->length - 1) {
            cout << "Linked List Index Out Of Bound" << endl;
            return -1;
        }

        if (index == 0) {
            Node* temp = this->Head;

            int deletedItem = this->Head->value;

            this->Head = this->Head->next;

            if (this->Head == NULL) {
                this->End = NULL;
            } else {
                this->Head->prev = NULL;
            }

            free(temp);
            this->length--;
            return deletedItem;
        }

        if (index == this->length - 1) {

            Node* temp = this->End;

            int deletedItem = this->End->value;

            this->End = this->End->prev;

            if (this->End == NULL) {
                this->Head = NULL;
            } else {
                this->End->next = NULL;
            }

            free(temp);
            this->length--;
            return deletedItem;

        }

        Node* node = this->Head;
        for (int i=0; i<index; i++) {
            node = node->next;
        }

        Node* temp = node->next;

        int deletedItem = node->value;
        
        node->prev->next = node->next;
        node->next->prev = node->prev;

        free(temp);
        this->length--;
        return deletedItem;

    }

    void Display() {

        cout << "[";
        Node* node = this->Head;
        while (node != NULL) {
            cout << node->value << ", ";
            node = node->next;
        }
        cout << "]" << endl;

    }

    void DisplayReverse() {

        cout << "[";
        Node* node = this->End;
        while (node != NULL) {
            cout << node->value << ", ";
            node = node->prev;
        }
        cout << "]" << endl;

    }

};

int main() {

    LinkedList l;

    l.Insert(0, 10);
    l.Insert(1, 20);
    l.Insert(2, 30);    
    l.Insert(1, 15);
    l.Insert(2, 18);
    l.Delete(0);
    l.Delete(3);
    l.Delete(1);

    l.Display();
    
    l.DisplayReverse();

    return 0;
}