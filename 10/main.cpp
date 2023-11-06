#include <bits/stdc++.h> 
using namespace std; 
    
typedef struct Node {  
    int value;  
    Node *left;  
    Node *right;  
    int height;  
} Node;  

class AVLTree {

    public:

    Node* rootNode;

    AVLTree() {
        this->rootNode = NULL;
    }

    int height(Node *N) {  
        if (N == NULL) return 0;  
        return N->height;  
    }  
    
    int max(int a, int b) {  
        return (a > b)? a : b;  
    } 

    Node* newNode(int key) {  
        Node* node = new Node(); 
        node->value = key;  
        node->left = NULL;  
        node->right = NULL;  
        node->height = 1;   
        return node;  
    }  
    
    Node *rightRotate(Node *y) {  
        Node *x = y->left;  
        Node *T2 = x->right;  
    
        // Perform rotation  
        x->right = y;  
        y->left = T2;  
    
        // Update heights  
        y->height = this->max(this->height(y->left), this->height(y->right)) + 1;  
        x->height = this->max(this->height(x->left), this->height(x->right)) + 1;  
    
        // Return new root  
        return x;  
    }  

    Node *leftRotate(Node *x) {  
        Node *y = x->right;  
        Node *T2 = y->left;  
    
        // Perform rotation  
        y->left = x;  
        x->right = T2;  
    
        // Update heights  
        x->height = this->max(this->height(x->left), this->height(x->right)) + 1;  
        y->height = this->max(this->height(y->left), this->height(y->right)) + 1;  
    
        // Return new root  
        return y;  
    }  
    
    // Get Balance factor of node N  
    int getBalance(Node *N) {  
        if (N == NULL) return 0;  
        return this->height(N->left) - this->height(N->right);  
    }  

    Node* insert(Node* node, int value) {  
        if (node == NULL) {
            return this->newNode(value);
        }
    
        if (value <= node->value)  
            node->left = this->insert(node->left, value);  
        else if (value > node->value)  
            node->right = this->insert(node->right, value);  
    
        node->height = 1 + this->max(this->height(node->left), this->height(node->right));  
    
        int balance = this->getBalance(node);  
    
        // Left Left Case  
        if (balance > 1 && value < node->left->value)  
            return this->rightRotate(node);  
    
        // Right Right Case  
        if (balance < -1 && value > node->right->value) {
            return this->leftRotate(node);  
        }
    
        // Left Right Case  
        if (balance > 1 && value > node->left->value) {  
            node->left = this->leftRotate(node->left);  
            return this->rightRotate(node);  
        }  
    
        // Right Left Case  
        if (balance < -1 && value < node->right->value) {  
            node->right = this->rightRotate(node->right);  
            return this->leftRotate(node);  
        }  
    
        return node;  
    } 

    void Insert(int value) {
        this->rootNode = this->insert(this->rootNode, value); 
    }

    void DisplaySubTree(Node* node, int indent, int side) {

        if (this->rootNode == NULL) return;

        for (int i=0; i<indent; i++) {
            cout << "    ";
        }

        if (side == 1) {
            cout << "L";
        } else if (side == 2) {
            cout << "R";
        }

        if (node->left == NULL) {
            cout << "|" << node->value << endl;
        } else {
            cout << "\\" << node->value << endl;
        }

        if (node->left != NULL) {
            this->DisplaySubTree(node->left, indent + 1, 1);
        }

        if (node->right != NULL) {
            this->DisplaySubTree(node->right, indent + 1, 2);
        }

    }

};

int main() {  

    int choice, temp;
    AVLTree avl;

    while (true) {

        cout << "\n---- AVL Tree ----" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {

            cout << "Enter value to insert: ";
            cin >> temp;

            avl.Insert(temp);

        } else if (choice == 2) {

            avl.DisplaySubTree(avl.rootNode, 0, 0);
            
        } else if (choice == 3) {

            cout << "\n--------- Author ----------------" << endl;
    		cout << "Ali Izzath Shazin" << endl;
    		cout << "220071601028" << endl;
    		cout << "B. Tech CSE A" << endl;
            break;

        } else {

            cout << "Invalid Option" << endl;

        }
    
    }

    return 0;  
} 