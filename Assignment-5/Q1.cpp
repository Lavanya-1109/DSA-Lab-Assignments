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
void insertAtBeginning(int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(int val)
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
void insertBefore(int target, int val)
{
    if (head == NULL)
        return;

    if (head->data == target)
    {
        insertAtBeginning(val);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL && temp->next->data != target)
        temp = temp->next;

    if (temp->next == NULL)
    {
        cout << "Node not found." << endl;
        return;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAfter(int target, int val)
{
    Node *temp = head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Node not found." << endl;
        return;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteFromBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}
void deleteFromEnd()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}
void deleteNode(int target)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    if (head->data == target)
    {
        deleteFromBeginning();
        return;
    }

    Node *temp = head;
    while (temp->next != NULL && temp->next->data != target)
        temp = temp->next;

    if (temp->next == NULL)
    {
        cout << "Node not found." << endl;
        return;
    }

    Node *delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
}
void searchNode(int val)
{
    Node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            cout << "Node found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found." << endl;
}
void display()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node *temp = head;
    cout << "Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    int choice, val, target;

    while (1)
    {
        cout << "MENU" << endl;
        cout << "1.Insert at Beginning" << endl;
        cout << "2.Insert at End" << endl;
        cout << "3.Insert Before Node" << endl;
        cout << "4.Insert After Node" << endl;
        cout << "5.Delete from Beginning" << endl;
        cout << "6.Delete from End" << endl;
        cout << "7.Delete Specific Node" << endl;
        cout << "8.Search Node" << endl;
        cout << "9.Display List" << endl;
        cout << "0.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertAtEnd(val);
            break;
        case 3:
            cout << "Enter target node value: ";
            cin >> target;
            cout << "Enter new value: ";
            cin >> val;
            insertBefore(target, val);
            break;
        case 4:
            cout << "Enter target node value: ";
            cin >> target;
            cout << "Enter new value: ";
            cin >> val;
            insertAfter(target, val);
            break;
        case 5:
            deleteFromBeginning();
            break;
        case 6:
            deleteFromEnd();
            break;
        case 7:
            cout << "Enter node value to delete: ";
            cin >> val;
            deleteNode(val);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> val;
            searchNode(val);
            break;
        case 9:
            display();
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}