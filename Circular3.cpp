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
void deleteNode(Node *head, Node *node)
{
    Node *temp = head;
    if (head == node)
    {
        head = node->next;
    }
    while (temp->next != node)
    {
        temp = temp->next;
    }
    temp->next = node->next;

    free(node);
    return;
}

int digitSum(int num)
{
    int sum = 0;
    while (num)
    {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}

void deleteEven(Node *head)
{
    Node *node = head;
    Node *next;
    do
    {
        if (!(digitSum(node->data) & 1))
        {
            deleteNode(head, node);
        }
        next = node->next;
        node = next;
    } while (node != head);
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
    deleteEven(head);
    display(head);

    return 0;
}