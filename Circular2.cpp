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
void func(Node *&head, int n)
{
    Node *temp = head;
    int sum = 0;
    while (temp->next != head)
    {
        sum += temp->data;
        temp = temp->next;
    }
    sum += temp->data;
    //cout << sum;
    Node *temp2 = head;
    while (temp2->next != head)
    {
        temp2->data = sum - temp2->data;
        temp2 = temp2->next;
    }
    temp2->data = sum - temp2->data;

    display(temp->next);
}
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
int main()
{
    int n;
    cout << "Enter no of nodes"
         << "\n";
    cin >> n;
    Node *head = NULL;
    while (n != 0)
    {
        int temp;
        cin >> temp;
        insertAtTail(head, temp);
        n--;
    }
    cout << "Modified function"
         << "\n";
    func(head, n);
    return 0;
}