#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int count;
    Node *left, *right;

    Node(int k)
    {
        data = k;
        count = 1;
        left = right = NULL;
    }
};

Node *insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);

    if (x < root->data)
        root->left = insert(root->left, x);

    else if (x > root->data)
        root->right = insert(root->right, x);

    else if (x == root->data)
        (root->count)++;

    return root;
}

void levelorder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();

            int x = curr->count;
            cout << curr->data << '(' << x << ')' << " ";

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        cout << endl;
    }
}

Node *minValue(Node *node)
{
    Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

Node *delNode(Node *root,
              int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = delNode(root->left, data);

    else if (data > root->data)
        root->right = delNode(root->right, data);

    else
    {
        if (root->count > 1)
        {
            (root->count)--;
            return root;
        }

        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValue(root->right);

        root->data = temp->data;

        root->right = delNode(root->right,
                              temp->data);
    }
    return root;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, v[i]);
    }

    //levelorder(root);
    Node *temp = delNode(root, 20);

    levelorder(root);

    return 0;
}