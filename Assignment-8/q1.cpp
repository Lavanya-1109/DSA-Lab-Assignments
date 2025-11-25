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

// Preorder (Root Left Right)
void preorder(Node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder (Left Root Right)
void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder (Left Right Root)
void postorder(Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);

    cout << "Preorder: ";
    preorder(root);
    
    cout << "\nInorder: ";
    inorder(root);
    
    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}