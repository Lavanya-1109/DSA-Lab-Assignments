#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *head = NULL;
void insert(int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void display()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
}
int Delete(int key)
{
    int count = 0;
    while (head != NULL && head->data == key)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->data == key)
        {
            Node *delNode = curr->next;
            curr->next = curr->next->next;
            delete delNode;
            count++;
        }
        else
        {
            curr = curr->next;
        }
    }
    return count;
}
int main()
{
    insert(1);
    insert(2);
    insert(1);
    insert(2);
    insert(1);
    insert(3);
    insert(1);
    cout << "Original Linked List:";
    display();
    int key = 1;
    int cnt = Delete(key);
    cout << "Count:" << cnt << endl;
    cout << "Updated Linked List: ";
    display();
    return 0;
}