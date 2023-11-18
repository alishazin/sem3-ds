#include <iostream>
using namespace std;

typedef struct Node {
    int value;
    int height;
    Node* left;
    Node* right;
} Node; 

class AVL {

    public:

    Node* root;

    AVL(int value) {
        this->root = this->createNode(value);
    }

    Node* createNode(int value) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->value = value;
        node->height = 1;
        node->left = NULL;
        node->right = NULL;

        return node;
    }

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int max(int a, int b) {
        return a > b ? a : b; 
    }

    int getBalance(Node* node) {
        if (node == NULL) return 0;
        return this->height(node->left) - this->height(node->right);
    }

    Node *rightRotate(Node *z) {  
        Node *y = z->left;  
        Node *T2 = y->right;  
    
        y->right = z;  
        z->left = T2;  
    
        z->height = this->max(this->height(z->left), this->height(z->right)) + 1;  
        y->height = this->max(this->height(y->left), this->height(y->right)) + 1;  
    
        return y;  
    }  

    Node *leftRotate(Node *z) {  
        Node* y = z->right;
        Node* T2 = y->left;

        y->left = z;
        z->right = T2;

        z->height = this->max(this->height(z->right), this->height(z->left));
        y->height = this->max(this->height(y->right), this->height(y->left));

        return y;
    }

    void Insert(int value) {
        this->root = this->_Insert(this->root, value);
    }

    Node* _Insert(Node* root, int value) {

        if (root == NULL) {
            return this->createNode(value);
        }

        if (value <= root->value) {
            root->left = this->_Insert(root->left, value);
        } else if (value > root->value) {
            root->right = this->_Insert(root->right, value);
        }

        root->height = 1 + max(this->height(root->left), this->height(root->right));

        int balance = this->getBalance(root);

        if (balance > 1 && value < root->left->value) {
            return this->rightRotate(root);
        }

        if (balance < -1 && value > root->right->value) {
            return this->leftRotate(root);
        }
        
        if (balance > 1 && value > root->left->value) {
            root->left = this->leftRotate(root->left); 
            return this->rightRotate(root);
        }

        if (balance < -1 && value < root->right->value) {
            root->right = this->rightRotate(root->right);
            return this->leftRotate(root);
        }

        return root;

    }

    void Display(Node* root, int indent, int side) {

        for (int i=0; i<indent; i++) {
            cout << "    ";
        }

        if (side == 1) {
            cout << "L";
        } else if (side == 2) {
            cout << "R";
        }

        if (root->left == NULL && root->right == NULL) {
            cout << "|" << root->value << endl;
        } else {
            cout << "\\" << root->value << endl;
        }

        if (root->left != NULL) {
            this->Display(root->left, indent+1, 1);
        } 
        
        if (root->right != NULL) {
            this->Display(root->right, indent+1, 2);
        }

    }

};


int main() {

    AVL avl(10);

    avl.Insert(5);
    avl.Insert(15);
    avl.Insert(12);
    avl.Insert(11);
    avl.Insert(9);
    avl.Insert(8);
    avl.Insert(4);
    avl.Insert(3);

    avl.Display(avl.root, 0, 0);

    return 0;
}