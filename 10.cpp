Q6.(a)
#include <bits/stdc++.h>
    using namespace std;
struct node
{
    int d;
    node *next;
};
node *root = NULL;
node *newnode(int n)
{
    node *temp = new node();
    temp->d = n;
    temp->next = NULL;
    return temp;
}
void Insert(int n)
{
    node *temp = newnode(n);
    if (!root)
    {
        root = temp;
    }
    else
    {
        node *p = root;
        while (p->next)
        {
            p = p->next;
        }
        p->next = temp;
    }
    return;
}
void dis()
{
    node *p = root;
    while (p)
    {
        cout << p->d << " ";
        p = p->next;
    }
    return;
}
node *swap(node *a, node *b)
{
    if (a == root)
    {
        root = b;
        a->next = b->next;
        b->next = a;
    }
    else
    {
        node *p = root;
        while (p->next != a)
        {
            p = p->next;
        }
        p->next = b;
        a->next = b->next;
        b->next = a;
    }
    return a;
}
void bubble_sort(int n)
{
    for (int i = 0; i < n; i++)
    {
        bool f = false;
        node *p = root;
        int j = 0;
        while (p->next && j < n - i - 1)
        {
            if (p->d > p->next->d)
            {
                p = swap(p, p->next);
                f = true;
            }
            else
            {
                p = p->next;
            }
            j++;
        }
        if (!f)
        {
            break;
        }
    }
}
int main()
{
    cout << "Monish soni" << endl;
    for (int i = 0; i < 5; i++)
    {
        Insert(5 - i);
    }
    dis();
    cout << endl;
    cout << "after bubble sort:-" << endl;
    bubble_sort(5);
    dis();
}

(b)
#include <bits/stdc++.h>
    using namespace std;

struct LLNode
{
    int data;
    LLNode *next;
};

void insertAtBeginning(LLNode **head, int dataToBeInserted)
{
    LLNode *curr = new LLNode;
    curr->data = dataToBeInserted;
    curr->next = NULL;

    if (*head == NULL)
    {
        *head = curr;
    }
    else
    {
        curr->next = *head;
        *head = curr;
    }
}
void display(LLNode **head)
{

    LLNode *temp = *head;
    while (temp != NULL)
    {

        if (temp->next != NULL)
            cout << temp->data << " ";
        else
            cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}
LLNode *getTail(LLNode *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;

    return cur;
}
LLNode *partition(LLNode *head, LLNode *end, LLNode **newHead, LLNode **newEnd)
{
    LLNode *pivot = end;
    LLNode *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;

            LLNode *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if ((*newHead) == NULL)
        (*newHead) = pivot;
    (*newEnd) = tail;
    return pivot;
}
LLNode *quickSortRecur(LLNode *head, LLNode *end)
{
    if (!head || head == end)
        return head;

    LLNode *newHead = NULL, *newEnd = NULL;
    LLNode *pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot)
    {

        LLNode *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        newHead = quickSortRecur(newHead, tmp);
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}
void quickSort(LLNode **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
int main()
{
    cout << "Monish Soni" << endl;
    LLNode *head = NULL;
    LLNode *tail = NULL;
    insertAtBeginning(&head, 36);
    insertAtBeginning(&head, 16);
    insertAtBeginning(&head, 55);
    insertAtBeginning(&head, 0);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 3);
    cout << "Linked List before sorting \n";
    display(&head);
    quickSort(&head);
    cout << "Linked List after sorting \n";
    display(&head);
    return 0;
}

(C)
#include <bits/stdc++.h>
    using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *SortedMerge(Node *a, Node *b)
{
    Node *result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
void FrontBackSplit(Node *source, Node **frontRef, Node **backRef)
{
    Node *fast;
    Node *slow;
    slow = source;
    fast = source->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
void Merge(Node **headRef)
{
    Node *head = *headRef;
    Node *a;
    Node *b;
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    FrontBackSplit(head, &a, &b);
    Merge(&a);
    Merge(&b);
    *headRef = SortedMerge(a, b);
}
void dis(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main()
{
    cout << "Monish Soni" << endl;
    Node *res = NULL;
    Node *a = NULL;
    push(&a, 88);
    push(&a, 0);
    push(&a, 65);
    push(&a, 23);
    push(&a, 35);
    push(&a, 29);
    dis(a);
    cout << endl;
    Merge(&a);
    cout << "Sorted Linked List is: \n";
    dis(a);
    return 0;
}

(d)
#include <bits/stdc++.h>
    using namespace std;
struct node
{
    int d;
    node *next;
};
node *root = NULL;
node *newnode(int n)
{
    node *temp = new node();
    temp->d = n;
    temp->next = NULL;
    return temp;
}
void Insert(int n)
{
    node *temp = newnode(n);
    if (!root)
    {
        root = temp;
    }
    else
    {
        node *p = root;
        while (p->next)
        {
            p = p->next;
        }
        p->next = temp;
    }
    return;
}
void dis()
{
    node *p = root;
    while (p)
    {
        cout << p->d << " ";
        p = p->next;
    }
    return;
}
void swap(node *a, node *b)
{
    if (a == root)
    {
        node *p = a->next, *q = root;
        while (q->next != b)
        {
            q = q->next;
        }
        a->next = b->next;
        q->next = a;
        root = b;
        b->next = p;
    }
    else
    {
        node *p = root, *q = b->next, *r = root;
        while (p->next != a)
        {
            p = p->next;
        }
        while (r->next != b)
        {
            r = r->next;
        }
        b->next = a->next;
        p->next = b;
        a->next = q;
        r->next = a;
    }
}
void selection_sort()
{
    node *temp = root;
    while (temp)
    {
        node *min = temp, *j = temp->next;
        while (j)
        {
            if (min->d > j->d)
            {
                min = j;
            }
            j = j->next;
        }
        node *curr = temp;
        swap(curr, min);
        temp = min->next;
    }
}
int main()
{
    cout << "Monish soni" << endl;
    for (int i = 0; i < 5; i++)
    {
        Insert(5 - i);
    }
    dis();
    cout << endl;
    cout << "after selection sort:-" << endl;
    selection_sort();
    dis();
}