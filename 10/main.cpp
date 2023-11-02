#include <bits/stdc++.h> 
using namespace std; 
    
typedef struct Node {  
    int value;  
    Node *left;  
    Node *right;  
    int height;  
} Node;  

Node* rootNode = NULL;

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
    y->height = max(height(y->left), height(y->right)) + 1;  
    x->height = max(height(x->left), height(x->right)) + 1;  
  
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
    x->height = max(height(x->left), height(x->right)) + 1;  
    y->height = max(height(y->left), height(y->right)) + 1;  
  
    // Return new root  
    return y;  
}  
  
// Get Balance factor of node N  
int getBalance(Node *N) {  
    if (N == NULL) return 0;  
    return height(N->left) - height(N->right);  
}  

Node* insert(Node* node, int value) {  
    if (node == NULL) {
        cout << "NEW" << endl;
        return newNode(value);
    }

    cout << "Before" << node->value << endl;
  
    if (value <= node->value)  
        node->left = insert(node->left, value);  
    else if (value > node->value)  
        node->right = insert(node->right, value);  

    cout << "After" << node->value << endl;
  
    node->height = 1 + max(height(node->left), height(node->right));  
  
    int balance = getBalance(node);  
  
    // Left Left Case  
    if (balance > 1 && value < node->left->value)  
        return rightRotate(node);  
  
    // Right Right Case  
    if (balance < -1 && value > node->right->value) {
        cout << "Left Rotation" << endl;  
        return leftRotate(node);  
    }
  
    // Left Right Case  
    if (balance > 1 && value > node->left->value) {  
        cout << "Left Right Rotation" << endl;  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && value < node->right->value) {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    return node;  
} 

void Insert(int value) {
    cout << "--------------" << endl;
    rootNode = insert(rootNode, value); 
    cout << "Root: " << rootNode->value << endl;
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
        cout << "|" << node->value << endl;
    } else {
        cout << "\\" << node->value << endl;
    }

    if (node->left != NULL) {
        DisplaySubTree(node->left, indent + 1, 1);
    }

    if (node->right != NULL) {
        DisplaySubTree(node->right, indent + 1, 2);
    }

}


int main() {  

    Insert(50);  
    Insert(60);  
    Insert(70);  
    Insert(80);  
    Insert(90);  
    Insert(40);  
    Insert(30);  

    DisplaySubTree(rootNode, 0, 0);

    return 0;  
} 