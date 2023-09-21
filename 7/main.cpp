#include <iostream>
#include <cstdlib>
using namespace std;

class LinkedListException {
    public:
    virtual string msg() = 0;
};

class LinkedListIndexOutOfBound: public LinkedListException {
    public:
    string msg() {
        return "Linked List Out of Bound";
    }
};

typedef struct Node {
    int value;
    Node* next;
} Node;

class LinkedList {

    Node* Head = NULL;
    int _length = 0;

    Node* createNode(int item) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->value = item;
        node->next = NULL;
        return node;
    }

    void Insert_Start(Node* node) {
        node->next = this->Head;
        this->Head = node;
        this->_length++;
    }
    
    void Insert_End(Node* node, Node* lastNode) {
        lastNode->next = node;
        this->_length++;
    }
    
    void Insert_Middle(Node* node, Node* prevNode) {
        node->next = prevNode->next;
        prevNode->next = node;
        this->_length++;
    }

    public:

    int length() {
        return this->_length;
    }
    
    void Insert(int index, int item) {
        Node* node = this->createNode(item);

        if (index < 0 || (index > this->_length)) throw LinkedListIndexOutOfBound();

        if (index == 0) {
            this->Insert_Start(node);
            return;
        }

        int count = 1;
        Node* temp = this->Head;
        
        while (temp->next != NULL) {
            if (count == index) {
                this->Insert_Middle(node, temp);
                return;
            }
            temp = temp->next;
            count++;
        }

        if (this->_length == index) {
            this->Insert_End(node, temp);
        }
        
    }

    int Delete(int index) {
        if (index < 0 || (index >= this->_length)) throw LinkedListIndexOutOfBound();

        if (index == 0) {
            // Deleting from the beginning
            Node* temp = this->Head;
            
            int deletedItem = this->Head->value;
            this->Head = this->Head->next;
            
            this->_length--;
            free(temp);
            return deletedItem;
        }

        // Accessing the node to delete
        Node* temp = this->Head->next;
        Node* prevValue = this->Head;
        for (int i=1; i<index; i++) {
            prevValue = temp;
            temp = temp->next;
        }

        // Deleting from the middle or end
        int deletedItem = temp->value;
        prevValue->next = temp->next;
        free(temp);
        this->_length--;

        return deletedItem;
    }

    void Display() {
        Node* node = this->Head;
        int count = 0;
        
        cout << "[";
        while (node != NULL) {
            cout << node->value;
            node = node->next;
            
            if (count != this->_length - 1) {
                cout << ", ";
            }
            count++;
        }
        cout << "]";
    }

};

int main() {

    int choice, temp1, temp2;
    LinkedList List;

    while (1) {
        cout << "---- Linked List Data Structure ----" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            
            cout << "Enter item to insert : ";
            cin >> temp1;
            
            cout << "Enter index to insert to : ";
            cin >> temp2;

            try {
                List.Insert(temp2, temp1);
            } catch(LinkedListException &e) {
                cout << "ERROR: " << e.msg() << endl;
            }

        } else if (choice == 2) {
            
            cout << "Enter index to delete : ";
            cin >> temp1;

            try {
                cout << "Deleted Item: " << List.Delete(temp1);
            } catch(LinkedListException &e) {
                cout << "ERROR: " << e.msg() << endl;
            }

        } else if (choice == 3) {
            
            List.Display();

        } else if (choice == 4) {
            
            cout << "\n--------- Author ----------------" << endl;
    		cout << "Ali Izzath Shazin" << endl;
    		cout << "220071601028" << endl;
    		cout << "B. Tech CSE A" << endl;
            break;

        } else {

            cout << "Invalid Option" << endl;

        }

        cout << endl;

    }

    return 0;
}