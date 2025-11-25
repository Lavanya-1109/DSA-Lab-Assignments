#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == curr)
            return i;
    }
    return -1;
}

Node* buildTree(int inorder[], int postorder[], int start, int end) {
    static int idx = end;  

    if(start > end)
        return NULL;

    int curr = postorder[idx];
    idx--;
    Node* node = new Node(curr);

    if(start == end)  
        return node;

    int pos = search(inorder, start, end, curr);

    node->right = buildTree(inorder, postorder, pos + 1, end);
    node->left = buildTree(inorder, postorder, start, pos - 1);

    return node;
}

void inorderPrint(Node* root) {
    if(root == NULL) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    int inorder[]  = {4, 2, 1, 5, 3};
    int postorder[] = {4, 2, 5, 3, 1};
    int n = 5;

    Node* root = buildTree(inorder, postorder, 0, n - 1);

    cout << "Inorder of constructed tree: ";
    inorderPrint(root);

    return 0;
}