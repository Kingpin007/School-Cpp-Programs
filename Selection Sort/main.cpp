#include <iostream>

using namespace std;

int main()
{
    int AR[50],item,mini=32565,pos,x=0;
    cout<<"Enter the 5 elements in the array): \n";
    for(int i=0;i<5;i++)
        cin>>AR[i];
    cout<<"\nThe array now is: "<<endl;
    for(int i=0;i<5;i++)
        cout<<AR[i]<<" ";
    for(int j=0;j<5;j++)
    {
        for(int i=j;i<5;i++)
        {
            if(AR[i]<mini)
            {
                mini=AR[i];
                pos=i;
            }
        }
        AR[pos]=AR[j];
        AR[j]=mini;
        mini=32565;
    }
    cout<<"\nThe array now is: "<<endl;
    for(int i=0;i<5;i++)
        cout<<AR[i]<<" ";
    return 0;
}
