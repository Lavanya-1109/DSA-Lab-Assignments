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

bool hasLoop(Node* head) {
    unordered_set<Node*> st;

    Node* temp = head;
    while(temp != NULL) {
        if(st.find(temp) != st.end())
            return true;
        st.insert(temp);
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // creating loop
    head->next->next->next->next = head->next;

    if(hasLoop(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}
