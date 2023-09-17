#include <iostream>
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

class BaseLinkedList {
    public:
    virtual void Traverse() = 0;
};

template <class DType = int> class LinkedList: public BaseLinkedList {

    class Node {
        public:
            DType value;
            Node* next;
    };

    Node* Head = NULL;
    int _length = 0;

    public:

    DType operator[](int index) {
        return this->Get(index);
    }

    int length() {
        return this->_length;
    }
    
    void Insert(int index, DType item) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->value = item;

        if (index < 0 || (index > this->_length)) throw LinkedListIndexOutOfBound();

        if (index == 0) {
            // Insert at the beginning
            node->next = this->Head;
            this->Head = node;
            this->_length++;
            return;
        }

        int count = 1;
        Node* temp = this->Head;
        
        while (temp->next != NULL) {
            if (count == index) {
                // Insert at middle
                node->next = temp->next;
                temp->next = node;
                this->_length++;
                return;
            }
            temp = temp->next;
            count++;
        }

        if (this->_length == index) {
            // Insert at the end
            temp->next = node;
            node->next = NULL;
            node->value = item;
            this->_length++;
        }
        
    }

    void Append(DType item) {
        this->Insert(this->_length, item);
    }

    DType Delete(int index) {
        if (index < 0 || (index >= this->_length)) throw LinkedListIndexOutOfBound();

        if (index == 0) {
            // Deleting from the beginning
            Node* temp = this->Head;
            
            DType deletedItem = this->Head->value;
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
        DType deletedItem = temp->value;
        prevValue->next = temp->next;
        free(temp);
        this->_length--;

        return deletedItem;
    }

    DType Get(int index) {
        if (index < 0 || (index >= this->_length)) throw LinkedListIndexOutOfBound();

        // Accessing the requested Node
        Node* temp = this->Head;
        for (int i=0; i<index; i++) {
            temp = temp->next;
        }

        return temp->value;
    }

    void Traverse() {
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

    void Blueprint() {
        Node* node = this->Head;
        int count = 0;
        cout << "HEAD = " << &(*node) << endl;
        while (node != NULL) {
           
            cout << "(" << &(*node) << ") -->";
           
            cout << " | ";
            cout << node->value;
            cout << " | ";
            cout << node->next;
            cout << " |" << endl;
           
            node = node->next;
            count++;            
        }
    }

    void Sort() {
        if (this->Head == NULL) return;

        int i, j;
        int swapped;
        for (i = 0; i < this->_length - 1; i++) {
            swapped = 0;
            
            Node* node = this->Head;
            for (j = 0; j < this->_length - i - 1; j++) {
                if (node->value > node->next->value) {
                    DType temp = node->value;
                    node->value = node->next->value;
                    node->next->value = temp;
                    swapped = 1;
                }
                node = node->next;
            }
    
            if (swapped == 0) break;
        }
    }

};

ostream& operator<<(ostream &out, BaseLinkedList &obj) {
    obj.Traverse();
    return out;
}

int main() {

    LinkedList l;
    l.Insert(0, 30);
    l.Insert(1, 10);
    l.Append(20);
    l.Insert(3, 40);
    l.Insert(3, 50);
    l.Insert(5, 60);
    l.Insert(0, 70);

    // cout << l << endl;
    // l.Blueprint();
    
    // cout << l.Delete(0) << endl;
    // cout << l << endl;
    // l.Blueprint();

    // cout << l.Delete(1) << endl;
    cout << l << endl;
    // l.Blueprint();

    l.Sort();
    cout << l << endl;

    // cout << l.Delete(4) << endl;
    // cout << l << endl;
    // l.Blueprint();
    
    // cout << l.Delete(4) << endl;
    // cout << l << endl;

    // cout << l.Delete(2) << endl;
    // cout << l << endl;

    // cout << l[0] << endl;
    // cout << l[1] << endl;
    // cout << l[2] << endl;

    // LinkedList<char> l;
    // l.Append('A');
    // l.Append('B');
    // l.Append('C');
    // l.Append('D');

    // cout << l << endl;
    // l.Blueprint();

    // cout << l.Delete(1) << endl;
    // cout << l << endl;

    return 0;
}