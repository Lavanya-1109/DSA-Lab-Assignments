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

struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int val) {
        data = val;
        prev = next = NULL;
    }
};

Node* insertBST(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

void inorderToArray(Node* root, int arr[], int &idx) {
    if (root == NULL) return;
    inorderToArray(root->left, arr, idx);
    arr[idx++] = root->data;
    inorderToArray(root->right, arr, idx);
}

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) merged[k++] = arr1[i++];
        else merged[k++] = arr2[j++];
    }
    while (i < n1) merged[k++] = arr1[i++];
    while (j < n2) merged[k++] = arr2[j++];
}

DLLNode* arrayToDLL(int merged[], int size) {
    if (size == 0) return NULL;
    DLLNode* head = new DLLNode(merged[0]);
    DLLNode* curr = head;
    for (int i = 1; i < size; i++) {
        DLLNode* newNode = new DLLNode(merged[i]);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }
    return head;
}

void printDLL(DLLNode* head) {
    cout << "Merged Doubly Linked List: ";
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;

    root1 = insertBST(root1, 10);
    root1 = insertBST(root1, 5);
    root1 = insertBST(root1, 15);

    root2 = insertBST(root2, 4);
    root2 = insertBST(root2, 12);
    root2 = insertBST(root2, 18);

    int arr1[10], arr2[10], merged[20];
    int n1 = 0, n2 = 0;

    inorderToArray(root1, arr1, n1);
    inorderToArray(root2, arr2, n2);

    mergeArrays(arr1, n1, arr2, n2, merged);

    int total = n1 + n2;
    DLLNode* head = arrayToDLL(merged, total);

    printDLL(head);

    return 0;
}