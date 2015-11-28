#include <iostream>
#include <cstdlib>

using namespace std;
struct Node
{
    int info;
    Node *next;
};
Node *start,*newptr,*save,*ptr;
Node *Create_New_Node(int);
void Insert_Beg(Node *);
void Display(Node *);
int main()
{
    start=NULL;
    int inf;
    char ch='Y';
    while(ch=='y'||ch=='Y')
    {
        system("cls");
        cout<<"\nEnter Information for the new node : ";
        cin>>inf;
        newptr=Create_New_Node(inf);
        if(newptr==NULL)
        {
            cout<<"\nCannot create new node! aborting!!\n";
            exit(1);
        }
        Insert_Beg(newptr);
        cout<<"\nNow the list is :\n";
        Display(start);
        cout<<"Do you want to enter more nodes (y/n) : ";
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
void Insert_Beg(Node * np)
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
void Display(Node *np)
{
    while(np!=NULL)
    {
        cout<<np->info<<"->";
        np=np->next;
    }
    cout<<"!!!\n";
}
