#include <iostream>

using namespace std;
struct Node
{
    int inf;
    Node *next;
}*start,*newptr,*save,*ptr,*rear;
Node* Create_New_Node(int n)
{
    newptr=new Node;
    newptr->inf=n;
    newptr->next=NULL;
    return newptr;
}
void Insert_End(Node *np)
{
    if(start==NULL)
        start=rear=np;
    else
    {
        rear->next=np;
        rear=np;
    }
}
void display(Node *np)
{
    while(np!=NULL)
    {
        cout<<np->inf<<"->";
        np=np->next;
    }
    cout<<"!!!";
}
void pop()
{
    if(start==NULL)
    {
        cout<<"Underflow!!";
        return;
    }
    ptr=start;
    start=start->next;
    delete ptr;
}
int main()
{
    start=NULL;
    int n;
    char ch='y';
    while(ch=='y'||ch=='Y')
    {
        cout<<"Enter information for new node: ";
        cin>>n;
        ptr=Create_New_Node(n);
        Insert_End(ptr);
        display(start);
        cout<<"\nWant to enter more (y/n) : ";
        cin>>ch;
    }
    ch='y';
    while(ch=='y'||ch=='Y')
    {
        cout<<"The list now is: ";
        display(start);
        cout<<"Want to delete element (y/n): ";
        cin>>ch;
        if(ch=='y'||ch=='Y')
            pop();
    }
    return 0;
}
