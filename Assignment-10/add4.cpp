#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) {
        data = v;
        next = NULL;
    }
};

void printList(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    // list 1: 10 -> 15 -> 4 -> 20
    Node* head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(20);

    // list 2: 8 -> 4 -> 2 -> 10
    Node* head2 = new Node(8);
    head2->next = new Node(4);
    head2->next->next = new Node(2);
    head2->next->next->next = new Node(10);

    unordered_set<int> st1, st2;

    Node* temp = head1;
    while(temp) {
        st1.insert(temp->data);
        temp = temp->next;
    }

    temp = head2;
    while(temp) {
        st2.insert(temp->data);
        temp = temp->next;
    }

    cout << "Intersection: ";
    for(int x : st1) {
        if(st2.find(x) != st2.end())
            cout << x << " ";
    }
    cout << endl;

    cout << "Union: ";
    unordered_set<int> uni = st1;
    for(int x : st2)
        uni.insert(x);

    for(int x : uni)
        cout << x << " ";

    return 0;
}
