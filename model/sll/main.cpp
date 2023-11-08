#include <iostream>
using namespace std;

typedef struct Node {
    int value;
    Node* next;
} Node;

class LinkedList {

    public:

    Node* Head;
    int length;

    LinkedList() {
        this->Head = NULL;
        this->length = 0;
    }

    Node* createNode(int value) {

        Node* node = (Node*) malloc(sizeof(Node));
        node->value = value;
        node->next = NULL;

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
            this->length++;
            return;
        }

        if (index == this->length) {
            
            Node* node = this->Head;
            while (node->next != NULL) {
                node = node->next;
            }

            node->next = newNode;
            this->length++;
            return;

        }

        Node* node = this->Head;
        for (int i=0; i<index-1; i++) {
            node = node->next;
        }

        newNode->next = node->next;
        node->next = newNode;
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

            free(temp);
            this->length--;
            return deletedItem;
        }

        Node* node = this->Head;
        for (int i=0; i<index-1; i++) {
            node = node->next;
        }

        Node* temp = node->next;

        int deletedItem = node->next->value;
        node->next = NULL;

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

};

int main() {

    LinkedList l;

    l.Insert(0, 10);
    l.Insert(1, 20);
    l.Insert(2, 50);
    l.Insert(0, 5);
    l.Insert(3, 15);

    l.Display();

    cout << l.Delete(4) << endl;
    
    l.Display();

    return 0;
}