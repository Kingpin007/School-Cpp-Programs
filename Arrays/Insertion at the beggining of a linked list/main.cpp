#include <iostream>

using namespace std;
struct Node
{
    int inf;
    Node *next;
}*start,*newptr,*save,*ptr;
Node* Create_New_Node(int n)
{
    newptr=new Node;
    newptr->inf=n;
    newptr->next=NULL;
    return newptr;
}
void Insert_Beg(Node *np)
{
    if(start==NULL)
        start=np;
    else
    {
        save=start;
        start=np;
        start->next=save;
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
        Insert_Beg(ptr);
        display(start);
        cout<<"\nWant to enter more (y/n) : ";
        cin>>ch;
    }
    return 0;
}
