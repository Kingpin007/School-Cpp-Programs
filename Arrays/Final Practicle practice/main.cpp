#include <iostream>

using namespace std;
struct Node
{
    int inf;
    Node *next;
}*ptr,*save,*start=NULL,*rear;
Node* CreateNode(int);
void InsertBeg(Node*);
void InsertEnd(Node*);
void Display(Node*);
int main()
{
    int inf;
    char ch='y';
    while(ch=='Y'||ch=='y')
    {
        cout<<"Enter information to be entered in the linked list: ";
        cin>>inf;
        ptr=CreateNode(inf);
        InsertEnd(ptr);
        cout<<"The linked list now is:\n";
        Display(start);
        cout<<"Want to enter more elements?(y/n) : ";
        cin>>ch;
    }
    return 0;
}
Node* CreateNode(int n)
{
    ptr=new Node;
    ptr->inf=n;
    ptr->next=NULL;
    return ptr;
}
void InsertBeg(Node* np)
{
    if(start==NULL)
        start=np;
    else
    {
        save=start;
        start=np;
        np->next=save;
    }
}
void InsertEnd(Node* np)
{
    if(start==NULL)
        start=rear=np;
    else
    {
        rear->next=np;
        rear=np;
    }
}
void Display(Node *np)
{
    while(np!=NULL)
    {
        cout<<np->inf<<"-->";
        np=np->next;
        if(np==NULL)
            cout<<"!!!\n";
    }
}
