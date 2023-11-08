#include <iostream>
using namespace std;

typedef struct Node {
    int value;
    Node* left;
    Node* right;
} Node;

class BST {

    public:

    Node* root;

    Node* createNode(int value) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->value = value;
        node->left = NULL;
        node->right = NULL;

        return node;
    };

    BST(int value) {
        this->root = this->createNode(value);
    }

    void Insert(int value) {

        Node* newNode = this->createNode(value);
        Node* prevNode = NULL;
        Node* root = this->root;

        while (root != NULL) {

            prevNode = root;
            if (newNode->value <= root->value) {
                root = root->left;
            } else {
                root = root->right;
            }

        }

        if (newNode->value <= prevNode->value) {
            prevNode->left = newNode;
        } else {
            prevNode->right = newNode;
        }

    }

    void Display(Node* node, int indent, int side) {

        for (int i=0; i<indent; i++) {
            cout << "    ";
        }

        if (side == 1) {
            cout << "L";
        } else if (side == 2) {
            cout << "R";
        }

        if (node->left == NULL && node->right == NULL) {
            cout << "|" << node->value << endl;
        } else {
            cout << "\\" << node->value << endl;
        }

        if (node->left != NULL) {
            this->Display(node->left, indent + 1, 1);
        }
        
        if (node->right != NULL) {
            this->Display(node->right, indent + 1, 2);
        }

    }

    void In_Order_Traversal(Node* root) {

        if (root) {
            this->In_Order_Traversal(root->left);
            cout << root->value << " ";
            this->In_Order_Traversal(root->right);
        }

    }

    void Pre_Order_Traversal(Node* root) {

        if (root) {
            cout << root->value << " ";
            this->Pre_Order_Traversal(root->left);
            this->Pre_Order_Traversal(root->right);
        }

    }

    void Post_Order_Traversal(Node* root) {

        if (root) {
            this->Post_Order_Traversal(root->left);
            this->Post_Order_Traversal(root->right);
            cout << root->value << " ";
        }

    }

};

int main() {

    BST bst(10);

    bst.Insert(5);
    bst.Insert(15);
    bst.Insert(4);
    bst.Insert(11);
    bst.Insert(17);

    bst.Display(bst.root, 0, 0);

    bst.In_Order_Traversal(bst.root);
    cout << endl;

    bst.Pre_Order_Traversal(bst.root);
    cout << endl;

    bst.Post_Order_Traversal(bst.root);
    cout << endl;

    return 0;
}