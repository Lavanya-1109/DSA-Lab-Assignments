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

// Function to check if BST using min/max range
bool isBST(Node* root, int minVal, int maxVal) {
    if(root == NULL) return true;

    if(root->data <= minVal || root->data >= maxVal)
        return false;

    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    
    if(isBST(root, -100000, 100000))
        cout << "This is a BST" << endl;
    else
        cout << "This is NOT a BST" << endl;

    return 0;
}