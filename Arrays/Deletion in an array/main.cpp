#include <iostream>

using namespace std;

int main()
{
    int a[6],b,pos,x;
    cout<<"Enter 5 elements of the array: ";
    for(int i=0;i<5;i++)
        cin>>a[i];
    cout<<"Enter Element to be deleted: ";
    cin>>b;
    for(pos=0;pos<5;pos++)
        if(a[pos]==b)
            break;
    cout<<"\nPosition is: "<<pos<<endl;
    for(x=pos;x<5;x++)
        a[x]=a[x+1];
    cout<<"Now the array is: ";
    for(int i=0;i<4;i++)
        cout<<a[i]<<" ";
    return 0;
}
