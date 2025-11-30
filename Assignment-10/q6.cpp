#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v) {
        data = v;
        left = right = NULL;
    }
};

bool findDuplicates(Node* root, unordered_set<int>& st) {
    if(root == NULL) return false;

    if(st.find(root->data) != st.end())
        return true;

    st.insert(root->data);

    return findDuplicates(root->left, st) ||
           findDuplicates(root->right, st);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->right = new Node(5); // duplicate

    unordered_set<int> st;

    if(findDuplicates(root, st))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}
