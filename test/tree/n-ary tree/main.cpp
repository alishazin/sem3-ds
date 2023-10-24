#include <iostream>
using namespace std;

typedef struct Node {
    int value;
    Node* parent;
    Node** children;
    int childrenSize;
} Node;

class Exception {
    public:
    virtual string msg() = 0;
};

class InvalidIndex: public Exception {
    public:
    string msg() {
        return "Index trying to access is invalid";
    }
};

class Tree {

    Node* CreateNode(int value) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->value = value;
        node->parent = NULL;
        node->children = NULL;
        node->childrenSize = 0;
        
        return node;
    }

    public:

    Node* Root;

    Tree(int value) {
        Node* newNode = this->CreateNode(value);
        this->Root = newNode;
    }

    void Insert(Node* parentNode, int value) {
        
        Node* newNode = this->CreateNode(value);
        Node** newArr = (Node**) malloc((parentNode->childrenSize + 1) * sizeof(Node*));

        for (int i=0; i<parentNode->childrenSize; i++) {
            newArr[i] = parentNode->children[i];
        }
        newArr[parentNode->childrenSize] = newNode;

        parentNode->childrenSize++;
        parentNode->children = newArr;

        newNode->parent = parentNode;
    }

    void DisplayNode(Node* node) {
        cout << "Value: " << node->value << endl;

        cout << "Parent: ";
        if (node->parent == NULL) {
            cout << "NULL" << endl;
        } else {
            cout << node->parent->value << endl;
        }

        cout << "Children: ";
        for (int i=0; i<node->childrenSize; i++) {
            cout << (node->children[i])->value << ", ";
        }
    }

    void DisplaySubTree(Node* node, int indent) {

        for (int i=0; i<indent; i++) {
            cout << "    ";
        }

        if (node->childrenSize == 0) {
            cout << "|" << node->value << endl;
        } else {
            cout << "\\" << node->value << endl;
        }

        if (node->childrenSize != 0) {
            for (int i=0; i<node->childrenSize; i++) {
                this->DisplaySubTree(node->children[i], indent + 1);
            }
        }

    }

    Node* AccessNode(Node* rootNode, int indices[], int size) {
        Node* temp = rootNode;

        for (int i=0; i<size; i++) {
            if (indices[i] >= temp->childrenSize || indices[i] < 0) throw InvalidIndex();
            temp = temp->children[indices[i]];
        }

        return temp;
    }

};

int main() {

    Tree tree(10);

    tree.Insert(tree.Root, 20);
    tree.Insert(tree.Root, 30);
    tree.Insert(tree.Root, 100);
    tree.Insert(tree.Root->children[0], 40);
    tree.Insert(tree.Root->children[0], 50);
    tree.Insert(tree.Root->children[1], 60);
    tree.Insert(tree.Root->children[1], 80);
    tree.Insert(tree.Root->children[1], 90);
    tree.Insert(tree.Root->children[1]->children[0], 70);

    tree.DisplaySubTree(tree.Root, 0);

    int a[] = {1, 0, 0};
    cout << tree.AccessNode(tree.Root, a, 3)->value << endl;
    tree.DisplayNode(tree.AccessNode(tree.Root, a, 3));

    return 0;
}