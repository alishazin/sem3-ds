// #include <iostream>
#include "bits/stdc++.h"
#include "stack.cpp"
using namespace std;

typedef struct Node {
    int value;
    Node* left;
    Node* right;
} Node;

class BinaryTreeException {
    public:
    virtual string msg() = 0;
};

class TreeOverflow: public BinaryTreeException {
    public:
    string msg() {
        return "Binary tree node cant have more than 2 children.";
    }
};

class Tree {

    Node* CreateNode(int value) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        
        return node;
    }

    public:

    Node* Root;

    Tree(int value) {
        Node* newNode = this->CreateNode(value);
        this->Root = newNode;
    }

    void Insert(Node* parent, int value) {

        Node* newNode = this->CreateNode(value);

        if (parent->left == NULL) {
            parent->left = newNode;
        } else if (parent->right == NULL) {
            parent->right = newNode;
        } else throw TreeOverflow();;

    }

    void DisplayNode(Node* node) {
        cout << "Value: " << node->value << endl;

        cout << "Left: ";
        if (node->left == NULL) {
            cout << "NULL" << endl;
        } else {
            cout << node->left->value << endl;
        }
        
        cout << "Right: ";
        if (node->right == NULL) {
            cout << "NULL" << endl;
        } else {
            cout << node->right->value << endl;
        }
    }

    void DisplaySubTree(Node* node, int indent) {

        for (int i=0; i<indent; i++) {
            cout << "    ";
        }

        if (node->left == NULL) {
            cout << "|" << node->value << endl;
        } else {
            cout << "\\" << node->value << endl;
        }

        if (node->left != NULL) {
            this->DisplaySubTree(node->left, indent + 1);
        }

        if (node->right != NULL) {
            this->DisplaySubTree(node->right, indent + 1);
        }

    }

    void In_Order_Traversal(Node* root) {
        // Left, Root, Right

        if (root == NULL)
            return;

        In_Order_Traversal(root->left);
        cout << root->value << ", ";
        In_Order_Traversal(root->right);
    }

    void Pre_Order_Traversal(Node* root) {
        // Root, Left, Right

        // if (root == NULL)
        //     return;

        // Stack<Node*> stack = Stack<Node*>();

        // while (root != NULL || !stack.isEmpty()) {

        //     if (root != NULL) {
        //         cout << root->value << ", ";
        //         stack.push(root);
        //         root = root->left;
        //     } else {
        //         root = stack.pop();
        //         root = root->right;
        //     }

        // }
        if (root != NULL) {
            cout<<root->value<<" ";
            Pre_Order_Traversal(root->left);
            Pre_Order_Traversal(root->right);
        }
    }

    void Post_Order_Traversal(Node* root) {

        if (root != NULL) {
            Post_Order_Traversal(root->left);
            Post_Order_Traversal(root->right);
            cout<<root->value<<" ";
        }
        // // Left, Right, Root

        // if (root == NULL)
        //     return;

        // Stack<Node*> stack = Stack<Node*>();
        // Node* prev = NULL;


        // do {

        //     while (root != NULL) {
        //         stack.push(root);
        //         root = root->left;
        //     }

        //     while (root == NULL && (!stack.isEmpty())) {

        //         root = stack.peek();

        //         if (root->right == NULL || root->right == prev) {
        //             cout << root->value << ", ";
        //             stack.pop();

        //             prev = root;
        //             root = NULL;
        //         } else {
        //             root = root->right;
        //         }

        //     }

        // } while (!stack.isEmpty());


    }

    void Level_Order_Travsersal(Node* root) {

        if (root == NULL)
            return;

        queue<Node*> q;
        cout << root->value << ", ";
        q.push(root);

        while (!q.empty()) {
            
            root = q.front();
            q.pop();

            if (root->left != NULL) {
                cout << root->left->value << ", ";
                q.push(root->left);
            }

            if (root->right != NULL) {
                cout << root->right->value << ", ";
                q.push(root->right);
            }

        }

        /*
            10
          20   30
        40 50 60 70

        q = 10   o =

        (10) q =      o = 10
        q = 20   o = 20
        q = 20, 30 o = 30

        (20) q = 30         o = 
        q = 30, 40     o = 40
        q = 30, 40, 50 o = 50
        
        (30) q = 40, 50 o = 
        q = 40, 50, 60     o = 60
        q = 40, 50, 60, 70 o = 70

        (70) q = 40, 50, 60 o = 0
        
        (60) q = 40, 50     o = 0
        
        (50) q = 40         o = 0
        
        (40) q =            o = 0


        */

    }

};

int main() {

    Tree tree(36);
    tree.Insert(tree.Root, 25);
    tree.Insert(tree.Root, 48);
    tree.Insert(tree.Root->left, 20);
    tree.Insert(tree.Root->left, 32);
    tree.Insert(tree.Root->left->left, 10);
    tree.Insert(tree.Root->left->left, 22);
    tree.Insert(tree.Root->left->left->left, 1);
    tree.Insert(tree.Root->left->left->left, 15);
    tree.Insert(tree.Root->right, 43);
    tree.Insert(tree.Root->right, 56);
    tree.Insert(tree.Root->right->right, 50);
    tree.Insert(tree.Root->right->right, 60);
    tree.Insert(tree.Root->right->right->right, 58);
    tree.Insert(tree.Root->right->right->right, 75);

    // tree.DisplayNode(tree.Root);

    tree.DisplaySubTree(tree.Root, 0);

    tree.In_Order_Traversal(tree.Root);
    cout << endl;

    tree.Pre_Order_Traversal(tree.Root);
    cout << endl;

    tree.Post_Order_Traversal(tree.Root);
    cout << endl;

    // tree.Level_Order_Travsersal(tree.Root);
    // cout << endl;



    return 0;
}