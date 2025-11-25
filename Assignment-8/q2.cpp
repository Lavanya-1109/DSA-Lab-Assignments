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

// Insert Node
Node* insert(Node* root, int val) {
    if(root == NULL) return new Node(val);
    if(val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Search Recursive
Node* searchRecursive(Node* root, int key) {
    if(root == NULL || root->data == key) return root;
    if(key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

// Search Non-Recursive
Node* searchNonRecursive(Node* root, int key) {
    while(root != NULL) {
        if(root->data == key) return root;
        if(key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// Find Minimum
int findMin(Node* root) {
    while(root->left != NULL) root = root->left;
    return root->data;
}

// Find Maximum
int findMax(Node* root) {
    while(root->right != NULL) root = root->right;
    return root->data;
}

// Inorder Successor
Node* inorderSuccessor(Node* root, Node* target) {
    Node* succ = NULL;
    while(root) {
        if(target->data < root->data) {
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}

// Inorder Predecessor
Node* inorderPredecessor(Node* root, Node* target) {
    Node* pred = NULL;
    while(root) {
        if(target->data > root->data) {
            pred = root;
            root = root->right;
        } else root = root->left;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Min: " << findMin(root) << endl;
    cout << "Max: " << findMax(root) << endl;

    int key = 40;
    Node* s1 = searchRecursive(root, key);
    Node* s2 = searchNonRecursive(root, key);
    cout << (s1 ? "Found Recursively\n" : "Not Found Recursively\n");
    cout << (s2 ? "Found Non-Recursively\n" : "Not Found Non-Recursively\n");

    Node* target = root->left->right; // 40
    Node* succ = inorderSuccessor(root, target);
    Node* pred = inorderPredecessor(root, target);
    cout << "Successor of " << target->data << " = " << (succ ? succ->data : -1) << endl;
    cout << "Predecessor of " << target->data << " = " << (pred ? pred->data : -1) << endl;

    return 0;
}