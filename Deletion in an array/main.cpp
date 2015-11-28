#include <iostream>

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
    cout<<"Enter item to be deleted: ";
    cin>>item;
    for(int i=0;i<5;i++)
    {
        if(AR[i]==item)
        {
            pos=i;
        }
    }
    for(x=pos;x<4;x++)
    {
        AR[x]=AR[x+1];
    }
    cout<<"\nThe array now is: "<<endl;
    for(int i=0;i<4;i++)
        cout<<AR[i]<<" ";
    return 0;
}
