#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int info;
    Node *next;
}   *front,*newptr,*save,*ptr,*rear;
Node *Create_New_Node(int);
void Insert_End(Node*);
void Display(Node*);
int main()
{
    int inf;
    char ch='y';
    front=rear=NULL;
    system("cls");
    while(ch=='y'||ch=='Y')
    {
        cout<<"Enter Information for new node: ";
        cin>>inf;
        newptr=Create_New_Node(inf);
        if(newptr==NULL)
        {
            cout<<"Cannot create new node\nAborting....";
            exit(1);
        }
        Insert_End(newptr);
        cout<<"\nNow the queue is: \n";
        Display(front);
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
void Insert_End(Node* np)
{
    if(front==NULL)
        front=rear=np;
    else
    {
        rear->next=np;
        rear=np;
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
