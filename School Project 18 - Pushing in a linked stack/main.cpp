#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int info;
    Node *next;
}   *top,*newptr,*save,*ptr;
Node *Create_New_Node(int);
void Push(Node*);
void Display(Node*);
int main()
{
    int inf;
    char ch='y';
    top=NULL;
    system("cls");
    while(ch=='y'||ch=='Y')
    {
        cout<<"Enter Information for new node: ";
        cin>>inf;
        newptr=Create_New_Node(inf);
        if(newptr==NULL)
        {
            cout<<"Cannot create new node\nAborting....";
            system("pause");
            exit(1);
        }
        Push(newptr);
        cout<<"\nNow the stack is: \n";
        Display(top);
        cout<<"\nPress Y to enter more nodes: ";
        cin>>ch;
    }
    return 0;
}
Node *Create_New_Node(int n)
{
    ptr=new Node;
    ptr->info=n;
    ptr->next=NULL;
    return ptr;
}
void Push(Node* np)
{
    if(top==NULL)
        top=np;
    else
    {
        save=top;
        top=np;
        np->next=save;
    }
}
void Display(Node* np)
{
    while(np!=NULL)
    {
        cout<<np->info<<"->";
        np=np->next;
    }
    cout<<"!!!\n";
}
