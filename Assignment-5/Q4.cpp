
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node *&anynode)
{
    Node *temp = anynode;

    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

void rev(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *forw;
    while (curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    head = prev;
}

void insert(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    cout << "Previous Linked List:" << endl;
    print(head);
    rev(head);
    cout << "Reversed:" << endl;
    print(head);
}