#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
node *newnode(int n)
{
    node *temp=new node;
    temp->data=n;
    temp->next=NULL;
    return temp;
}
void printlist(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        if(head->next)
            cout<<"->";
        head=head->next;
    }
    cout<<endl;
}
void reverseLL(node **head)
{
    node *prev=NULL,*curr=*head,*next;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
}
void rearrange(node **head)
{
    node *node1=*head,*node2=node1->next;
    while(node2&&node2->next)
    {
        node1=node1->next;
        node2=node2->next->next;
    }
    node *h1=*head,*h2=node1->next;
    node1->next=NULL;
    reverseLL(&h2);
    *head=newnode(0);
    node *curr=*head;
    while(h1||h2)
    {
        if(h1)
        {
            curr->next=h1;
            curr=curr->next;
            h1=h1->next;
        }
        if(h2)
        {
            curr->next=h2;
            curr=curr->next;
            h2=h2->next;
        }
    }
    *head=(*head)->next;
}
int main()
{
    node *head=newnode(1);
    head->next=newnode(2);
    head->next->next=newnode(3);
    head->next->next->next=newnode(4);
    head->next->next->next->next=newnode(5);
    head->next->next->next->next->next=newnode(6);
    head->next->next->next->next->next->next=newnode(7);
    printlist(head);
    rearrange(&head);
    printlist(head);
    return 0;
}
