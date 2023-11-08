#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node {
    int value;
    Node* left;
    Node* right;
} Node;

class BinarySearchTree {

    Node* CreateNode(int value) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        
        return node;
    }

    public:

    Node* Root;

    BinarySearchTree(int value) {
        Node* newNode = this->CreateNode(value);
        this->Root = newNode;
    }

    void Insert(int value) {

        Node* newNode = this->CreateNode(value);
        Node* root = this->Root;
        Node* prevRoot = NULL;

        while (root != NULL) {
            prevRoot = root;
            if (newNode->value <= root->value) {
                root = root->left;
            } else {
                root = root->right;
            }
        }

        if (newNode->value <= prevRoot->value) {
            prevRoot->left = newNode;
        } else {
            prevRoot->right = newNode;
        }

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

        if (node->left == NULL && node->right == NULL) {
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

    void In_Order_Traversal(Node* root) {

        if (root == NULL)
            return;

        In_Order_Traversal(root->left);
        cout<<root->value<<" ";
        In_Order_Traversal(root->right);

    }

    void Pre_Order_Traversal(Node* root) {

        if (root == NULL)
            return;

        cout<<root->value<<" ";
        Pre_Order_Traversal(root->left);
        Pre_Order_Traversal(root->right);

    }

    void Post_Order_Traversal(Node* root) {

        if (root == NULL)
            return;

        Post_Order_Traversal(root->left);
        Post_Order_Traversal(root->right);
        cout<<root->value<<" ";

    }

};

int main() {

    int choice, temp;

    cout << "Enter the root node value: ";
    cin >> temp;

    BinarySearchTree bst(temp);

    while (true) {

        cout << "\n---- Binary Search Tree (BST) ----" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Inorder Traversal" << endl;
        cout << "3. Preorder Traversal" << endl;
        cout << "4. Postorder Traversal" << endl;
        cout << "5. Display BST" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {

            cout << "Enter value to insert: ";
            cin >> temp;

            bst.Insert(temp);

        } else if (choice == 2) {

            cout << "Inorder => ";
            bst.In_Order_Traversal(bst.Root);
            cout << endl;

        } else if (choice == 3) {

            cout << "Preorder => ";
            bst.Pre_Order_Traversal(bst.Root);
            cout << endl;

        } else if (choice == 4) {

            cout << "Postorder => ";
            bst.Post_Order_Traversal(bst.Root);
            cout << endl;

        } else if (choice == 5) {

            bst.DisplaySubTree(bst.Root, 0, 0);

        } else if (choice == 6) {

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