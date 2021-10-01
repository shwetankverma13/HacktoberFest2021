#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;

    Node(int k)
    {
        key=k;
        left=NULL;
        right=NULL;
    }
};

Node* lca(Node* root,int n1,int n2)
{
    if(root==NULL)
    return NULL;

    if(root->key==n1 || root->key==n2)
    return root;

    Node *lca1=lca(root->left,n1,n2);
    Node *lca2=lca(root->right,n1,n2);

    if(lca1!=NULL && lca2!=NULL)
    return root;

    if(lca1!=NULL)
    return lca1;

    else 
    return lca2;


}

int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(60);
    root->right->right=new Node(70);

    int n1=40,n2=50;

    Node *x=lca(root,n1,n2);
    cout<<x->key;

    return 0;
}