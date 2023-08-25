#include <iostream>
#include <cstdlib>
using namespace std;

typedef union listItemStorage {

    short SHORT;
    int INT;
    long LONG;
    float FLOAT;
    double DOUBLE;
    char CHAR;

} listItemStorage;

class ListItem {

    listItemStorage item;
    int instance;

    friend class List;

    public:
        
        void display() {
            if (this->instance == 1) {
                cout << this->item.SHORT;
            } else if (this->instance == 2) {
                cout << this->item.INT;
            } else if (this->instance == 3) {
                cout << this->item.LONG;
            } else if (this->instance == 4) {
                cout << this->item.FLOAT;
            } else if (this->instance == 5) {
                cout << this->item.DOUBLE;
            } else if (this->instance == 6) {
                cout << this->item.CHAR;
            }
        }
};

class List {
    
    int _length;
    int _nestedLength;
    ListItem* _items;
    List* _nestedItems;
    int *nestedIndices;

    public:

        List() {
            this->_length = 0;
            this->_nestedLength = 0;
        }

        void append(short item) {

            ListItem itemObj;
            itemObj.instance = 1;

            listItemStorage storage;
            storage.SHORT = item;
            itemObj.item = storage;

            this->resize();
            this->_items[this->_length] = itemObj;
            this->_length++;
        }

        void append(int item) {

            ListItem itemObj;
            itemObj.instance = 2;

            listItemStorage storage;
            storage.INT = item;
            itemObj.item = storage;

            this->resize();
            this->_items[this->_length] = itemObj;
            this->_length++;
        }

        void append(long item) {

            ListItem itemObj;
            itemObj.instance = 3;

            listItemStorage storage;
            storage.LONG = item;
            itemObj.item = storage;

            this->resize();
            this->_items[this->_length] = itemObj;
            this->_length++;
        }

        void append(float item) {

            ListItem itemObj;
            itemObj.instance = 4;

            listItemStorage storage;
            storage.FLOAT = item;
            itemObj.item = storage;

            this->resize();
            this->_items[this->_length] = itemObj;
            this->_length++;
        }

        void append(double item) {

            ListItem itemObj;
            itemObj.instance = 5;

            listItemStorage storage;
            storage.DOUBLE = item;
            itemObj.item = storage;

            this->resize();
            this->_items[this->_length] = itemObj;
            this->_length++;
        }

        void append(char item) {

            ListItem itemObj;
            itemObj.instance = 6;

            listItemStorage storage;
            storage.CHAR = item;
            itemObj.item = storage;

            this->resize();
            this->_items[this->_length] = itemObj;
            this->_length++;
        }

        void append(List item) {

            this->resizeNested();
            this->resizeNestedIndices();
            this->resize();

            this->_nestedItems[this->_nestedLength] = item;
            this->nestedIndices[this->_nestedLength] = this->_length;

            this->_nestedLength++;
            this->_length++;

        }

        void resize() {
            ListItem* newItems = (ListItem*) malloc((this->_length + 1) * sizeof(ListItem));

            for (int i=0; i<this->_length; i++) {
                newItems[i] = this->_items[i];
            }
            this->_items = newItems;
        }

        void resizeNested() {
            List* newNestedItems = (List*) malloc((this->_nestedLength + 1) * sizeof(List));

            for (int i=0; i<this->_nestedLength; i++) {
                newNestedItems[i] = this->_nestedItems[i];
            }
            this->_nestedItems = newNestedItems;
        }

        void resizeNestedIndices() {
            int* newNestedIndices = (int*) malloc((this->_nestedLength + 1) * sizeof(int));

            for (int i=0; i<this->_nestedLength; i++) {
                newNestedIndices[i] = this->nestedIndices[i];
            }
            this->nestedIndices = newNestedIndices;
        }

        void display() {

            cout << "[";
            for (int i=0; i<this->_length; i++) {
                
                int nestedIndex = this->getNestedIndexIfExist(i);
                
                if (nestedIndex != -1) {
                    this->_nestedItems[nestedIndex].display();
                } else {
                    this->_items[i].display();
                
                    if (i != this->_length - 1) {
                        cout << ", ";
                    }
                }
            }
            cout << "], ";
        }

        int getNestedIndexIfExist(int index) {
            for (int i=0; i<this->_nestedLength; i++) {
                if (this->nestedIndices[i] == index) {
                    return i;
                }
            }
            return -1;
        }

};

int main() {

    List l;
    l.append(10);
    l.append(40);

    List l1;
    l1.append(100);
    l1.append(400);

    l.append(l1);
    l.append(1);

    List l2;
    l2.append(-120);
    l2.append(-240);
    
    List l3;
    l3.append(0.12);
    l3.append('A');
    l2.append(l3);
    
    l.append(l2);

    // short a = 20;
    // l.append(a);

    // int z = 20;
    // l.append(z);

    // float b = 20.255f;
    // l.append(b);
    // l.append(18.22f);

    // double c = 32.56;
    // l.append(c);
    // l.append(54.23);

    // long d = 23434;
    // l.append(d);

    // char e = 'A';
    // l.append(e);
    // l.append('B');

    l.display();

    return 0;
}