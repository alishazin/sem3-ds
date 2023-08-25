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

class ListReturn;

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
                }
                
                if (i != this->_length - 1) {
                    cout << ", ";
                }
            }
            cout << "]";
        }

        int getNestedIndexIfExist(int index) {
            for (int i=0; i<this->_nestedLength; i++) {
                if (this->nestedIndices[i] == index) {
                    return i;
                }
            }
            return -1;
        }

        ListReturn operator[](int index); 

};

class ListReturn {
    
    public:

        int type;
        string type_name;
        listItemStorage item;
        List list;

        void display() {

            cout << "{\n\ttype: " << this->type << "\n\ttype_name: " << this->type_name << "\n\t";

            if (this->type == 1) {
                cout << "item: " << this->item.SHORT;
            } else if (this->type == 2) {
                cout << "item: " << this->item.INT;
            } else if (this->type == 3) {
                cout << "item: " << this->item.LONG;
            } else if (this->type == 4) {
                cout << "item: " << this->item.FLOAT;
            } else if (this->type == 5) {
                cout << "item: " << this->item.DOUBLE;
            } else if (this->type == 6) {
                cout << "item: " << this->item.CHAR;
            } else if (this->type == 7) {
                cout << "list: ";
                this->list.display();
            }

            cout << "\n}";
        }

};

ListReturn List::operator[](int index) {
    int nestedIndex = this->getNestedIndexIfExist(index);

    ListReturn obj;
    if (nestedIndex == -1) {
        
        listItemStorage storageObj;

        if (this->_items[index].instance == 1) {
            obj.type = 1;
            obj.type_name = "SHORT";
        } else if (this->_items[index].instance == 2) {
            obj.type = 2;
            obj.type_name = "INT";
        } else if (this->_items[index].instance == 3) {
            obj.type = 3;
            obj.type_name = "LONG";
        } else if (this->_items[index].instance == 4) {
            obj.type = 4;
            obj.type_name = "FLOAT";
        } else if (this->_items[index].instance == 5) {
            obj.type = 5;
            obj.type_name = "DOUBLE";
        } else if (this->_items[index].instance == 6) {
            obj.type = 6;
            obj.type_name = "CHAR";
        }
        obj.item = this->_items[index].item;

    } else {

        obj.type = 7;
        obj.type_name = "LIST";
        obj.list = this->_nestedItems[nestedIndex];

    }
    return obj;
}

ostream& operator<<(ostream &out, List &obj) {
    obj.display();
    return out;
}

ostream& operator<<(ostream &out, ListReturn &obj) {
    obj.display();
    return out;
}

int main() {

    List l;
    l.append(10.55);
    l.append(40);

    List l1;
    l1.append(100);
    l1.append(400);

    l.append(l1);

    cout << l << endl;

    ListReturn ret = l[0];

    // cout << ret.type << endl;
    // cout << ret.type_name << endl;
    // cout << ret.item.INT << endl;
    cout << ret << endl;
    cout << ret.item.DOUBLE << endl;
    // ret.display();
    
    ListReturn ret2 = l[2];

    // cout << ret2.type << endl;
    // cout << ret2.type_name << endl;
    cout << ret2 << endl;
    cout << ret2.list << endl;

    ListReturn ret3 = ret2.list[0];
    // cout << ret3.type << endl;
    // cout << ret3.type_name << endl;
    cout << ret3.item.INT << endl;
    cout << ret3 << endl;

    return 0;
}