#include <iostream>

using namespace std;

int main()
{
    int AR[50],pos,x=0;
    cout<<"Enter the 5 elements in the array): \n";
    for(int i=0;i<5;i++)
        cin>>AR[i];
    cout<<"\nThe array now is: "<<endl;
    for(int i=0;i<5;i++)
        cout<<AR[i]<<" ";
    for(int i=0;i<5;i++)
        for(int j=0;j<4;j++)
            if(AR[j]>AR[j+1])
            {
                int temp=AR[j];
                AR[j]=AR[j+1];
                AR[j+1]=temp;
            }
    cout<<"\nThe array now is: "<<endl;
    for(int i=0;i<5;i++)
        cout<<AR[i]<<" ";
    return 0;
}
