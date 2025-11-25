#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void inorderUsingStack(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while(curr != NULL || !st.empty()) {
        while(curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}

int main() {
    // Creating simple Binary Tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->right = new Node(7);

    cout << "Inorder Traversal (Using Stack): ";
    inorderUsingStack(root);

    return 0;
}