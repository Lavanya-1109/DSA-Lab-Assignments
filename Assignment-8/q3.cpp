#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert a node
Node* insert(Node* root, int val) {
    if(root == NULL) return new Node(val);
    if(val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Find minimum value
int findMin(Node* root) {
    while(root->left != NULL) root = root->left;
    return root->data;
}

// Find maximum value
int findMax(Node* root) {
    while(root->right != NULL) root = root->right;
    return root->data;
}

// Height (Depth) of BST
int height(Node* root) {
    if(root == NULL) return -1; // depth = -1 for empty tree
    int leftH = height(root->left);
    int rightH = height(root->right);
    return max(leftH, rightH) + 1;
}

// Delete a node
Node* deleteNode(Node* root, int key) {
    if(root == NULL) return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: No child / One child
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Two children
        int minValue = findMin(root->right);     // Inorder Successor
        root->data = minValue;
        root->right = deleteNode(root->right, minValue);
    }
    return root;
}

// Inorder Traversal
void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int choice, val;

    while(true) {
        cout << "\n1.Insert\n2.Delete\n3.Display Inorder\n4.Find Min\n5.Find Max\n6.Find Depth\n7.Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                root = insert(root, val);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                root = deleteNode(root, val);
                break;

            case 3:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Min value: " << findMin(root) << endl;
                break;

            case 5:
                cout << "Max value: " << findMax(root) << endl;
                break;

            case 6:
                cout << "Depth of BST: " << height(root) << endl;
                break;

            case 7:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}