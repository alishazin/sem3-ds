#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

// Wrong

typedef struct Node {
    int value;
    Node* left;
    Node* right;
    int height;
} Node;

class AVLTree {

    Node* CreateNode(int value) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        node->height = 0;
        
        return node;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int height(Node *Node) {  
        if (Node == NULL) return 0;  
        return Node->height;  
    }  

    int getBalance(Node *Node) {  
        if (Node == NULL) return 0;  
        return height(Node->left) - height(Node->right);  
    } 

    Node* leftRotate(Node *x) {  
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

    public:

    Node* Root;

    AVLTree(int value) {
        Node* newNode = this->CreateNode(value);
        this->Root = newNode;
    }

    // void Insert(int value) {

    //     cout << "----" << endl;

    //     Node* newNode = this->CreateNode(value);
    //     Node* root = this->Root;

    //     stack<Node*> stack;

    //     while (root != NULL) {
    //         stack.push(root);
    //         if (newNode->value <= root->value) {
    //             root = root->left;
    //         } else {
    //             root = root->right;
    //         }
    //     }

    //     if (newNode->value <= stack.top()->value) {
    //         stack.top()->left = newNode;
    //     } else {
    //         stack.top()->right = newNode;
    //     }
    //     stack.push(newNode);

    //     Node* currentNode = NULL;
    //     Node* newRoot = NULL;

    //     while (!stack.empty()) {
    //         currentNode = stack.top();
    //         cout << currentNode->value << endl;
    //         newRoot = NULL;
    //         currentNode->height = 1 + max(this->height(currentNode->left), this->height(currentNode->right));
    //         cout << "Height: " << currentNode->height << endl;
            
    //         int balance = this->getBalance(stack.top());

    //         // Case 1: Right-Right
    //         if (balance < -1 && currentNode->right != NULL && value > currentNode->right->value) {
    //             newRoot = this->leftRotate(currentNode);
    //             cout << "Left Rotation" << endl;
    //         }
            
    //         // Case 2: Left-Left
    //         if (balance > 1 && currentNode->left != NULL && value < currentNode->left->value) {
    //             cout << "Right Rotation" << endl;
    //             newRoot = this->rightRotate(currentNode);
    //         }
            
    //         // Case 3: Left Right 
    //         if (balance > 1 && currentNode->left != NULL && value > currentNode->left->value) {
    //             cout << "Left Right Rotation" << endl;
    //             currentNode->left = this->leftRotate(currentNode->left);  
    //             newRoot = this->rightRotate(currentNode);
    //         }
            
    //         // Case 4: Right Left 
    //         if (balance < -1 && currentNode->right != NULL && value < currentNode->right->value) {
    //             cout << "Right Left Rotation" << endl;
    //             currentNode->right = this->rightRotate(currentNode->right);  
    //             newRoot = this->leftRotate(currentNode);
    //         }

    //         stack.pop();

    //         if (newRoot != NULL) {
    //             stack.push(newRoot);
    //         }

    //     }


    //     this->Root = currentNode;

    // }

    void Insert(int value) {
        this->Root = this->InternalInsert(this->Root, value);
    }

    Node* InternalInsert(Node* node, int value) {  
        
        if (node == NULL)  
            return this->CreateNode(value);
    
        if (value <= node->value)  
            node->left = this->InternalInsert(node->left, value);  
        else if (value > node->value)  
            node->right = this->InternalInsert(node->right, value);  
    
        node->height = 1 + this->max(this->height(node->left), this->height(node->right));  
    
        int balance = this->getBalance(node);  
    
        // Left Left Case  
        if (balance > 1 && value < node->left->value)  
            return this->rightRotate(node);  
    
        // Right Right Case  
        if (balance < -1 && value > node->right->value)  
            return this->leftRotate(node);  
    
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


    void DisplaySubTree(Node* node, int indent, int side) {

        for (int i=0; i<indent; i++) {
            cout << "    ";
        }

        if (side == 1) {
            cout << "L";
        } else if (side == 2) {
            cout << "R";
        }

        if (node->left == NULL) {
            cout << "|" << node->value << " (" << this->getBalance(node) << ")" << endl;
        } else {
            cout << "\\" << node->value << " (" << this->getBalance(node) << ")" << endl;
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

    // cout << "Enter the root node value: ";
    // cin >> temp;

    AVLTree avl(50);

    avl.Insert(60);
    avl.Insert(70);
    avl.Insert(80);
    avl.Insert(75);

    avl.DisplaySubTree(avl.Root, 0, 0);
    

    return 0;
}