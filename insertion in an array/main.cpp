#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int AR[50],item,pos,x;
    cout<<"Enter the 5 elements in the array(in ascending order): \n";
    for(int i=0;i<5;i++)
        cin>>AR[i];
    cout<<"\nThe array now is: "<<endl;
    for(int i=0;i<5;i++)
        cout<<AR[i]<<" ";
    cout<<"Enter item to be inserted: ";
    cin>>item;
    for(x=0;x<5;x++)
    {
        if(AR[x]>item)
        {
            pos=x;
            break;
        }
        else
            pos=x+1;
    }
    for(int i=5;i>=pos;i--)
    {
        AR[i+1]=AR[i];
        if(i==pos)
            AR[i]=item;
    }
    cout<<"\nThe array now is: "<<endl;
    for(int i=0;i<6;i++)
        cout<<AR[i]<<" ";
}
