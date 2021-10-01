#include<stdio.h>
#include<stdlib.h>

struct node
{
    int digit;
    struct node *next;
};
void traverse(struct node *head)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr=head;
    while(1==1)
    {
        printf("Value in the node %d\n",ptr->digit);
        ptr=ptr->next;
        if(ptr==head)
        {
            break;
        }
    }
}
int main()
{
    struct node *head=(struct node *)malloc(sizeof(struct node));
    struct node *s=(struct node *)malloc(sizeof(struct node));
    struct node *t=(struct node *)malloc(sizeof(struct node));
    struct node *f=(struct node *)malloc(sizeof(struct node));
    struct node *last=(struct node *)malloc(sizeof(struct node));

    head->digit=9;
    head->next=s;

    s->digit=26;
    s->next=t;

    t->digit=76;
    t->next=f;

    f->digit=96;
    f->next=last;

    last->digit=86;
    last->next=head;

    traverse(head);


    



    return 0;
}B
