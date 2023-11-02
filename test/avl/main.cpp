#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

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

    public:

    Node* Root;

    AVLTree(int value) {
        Node* newNode = this->CreateNode(value);
        this->Root = newNode;
    }

    void Insert(int value) {

        Node* newNode = this->CreateNode(value);
        Node* root = this->Root;

        stack<Node*> stack;

        while (root != NULL) {
            stack.push(root);
            if (newNode->value <= root->value) {
                root = root->left;
            } else {
                root = root->right;
            }
        }

        if (newNode->value <= stack.top()->value) {
            // stack.top()->height++;
            stack.top()->left = newNode;
        } else {
            // stack.top()->height++;
            stack.top()->right = newNode;

            // stack.pop();
        }

        while (!stack.empty()) {
            stack.top()->height = 1 + max(this->height(stack.top()->left), this->height(stack.top()->right));
            stack.pop();
        }

        // In_Order_Traversal(this->Root);

    }

    void In_Order_Traversal(Node* root) {

        if (root == NULL)
            return;

        In_Order_Traversal(root->left);
        root->height = 1 + max(this->height(root->left), this->height(root->right));
        In_Order_Traversal(root->right);

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
            cout << "|" << node->value << " (" << node->height << ")" << endl;
        } else {
            cout << "\\" << node->value << " (" << node->height << ")" << endl;
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

    cout << "Enter the root node value: ";
    cin >> temp;

    AVLTree avl(temp);

    avl.Insert(15);
    avl.Insert(5);
    avl.Insert(13);
    avl.Insert(20);
    avl.Insert(25);

    avl.DisplaySubTree(avl.Root, 0, 0);
    

    return 0;
}