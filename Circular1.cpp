#include <bits/stdc++.h>
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

void insertAthead(Node *&head, int val)
{

    Node *n = new Node(val);
    Node *temp = head;
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(Node *&head, int val)
{
    if (head == NULL)
    {
        insertAthead(head, val);
        return;
    }
    Node *n = new Node(val);
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void search(Node *&head, int val)
{
    Node *temp = head;
    int found = 0;
    int i = 0;
    if (temp != NULL)
    {
        while (true)
        {
            i++;
            if (temp->data == val)
            {
                found++;
                break;
            }
            temp = temp->next;
            if (temp == head)
            {
                break;
            }
        }
        if (found == 1)
        {
            cout << "index " << i << "\n";
        }
        else
        {
            cout << "NOT FOUND";
        }
    }
    else
    {
        cout << "List is empty"
             << "\n";
    }
}

void display(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << "  ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAthead(head, 5);
    display(head);

    search(head, 4);

    return 0;
}
