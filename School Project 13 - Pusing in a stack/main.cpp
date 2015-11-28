#include <iostream>
#include <cstdlib>

using namespace std;
int push(int[],int&,int);
void display(int[],int);
int main()
{
    int stack[50],item,top=-1,res;
    char ch='y';
    system("cls");
    while(ch=='y'||ch=='Y')
    {
        cout<<"\nEnter Item for insertion: ";
        cin>>item;
        res=push(stack,top,item);
        if(res==-1)
        {
            cout<<"Overflow!! Aborting";
            exit(1);
        }
        cout<<"\nThe stack now is: \n";
        display(stack,top);
        cout<<"\nWant to insert more elements (y/n): ";
        cin>>ch;
    }
    return 0;
}
int push(int stack[],int&top,int size)
{
    if(top==size-1) return -1;
    else
    {
        top++;
        stack[top]=size;
    }
    return 0;
}
void display(int stack[],int top)
{
    cout<<stack[top]<<"<--"<<endl;
    for(int i=top-1;i>=0;i--)
        cout<<stack[i]<<endl;
}
