#include <iostream>

using namespace std;

int main()
{
    int a[6],b,pos,x;
    cout<<"Enter 5 elements of the array(in ascending order): ";
    for(int i=0;i<5;i++)
        cin>>a[i];
    cout<<"Enter Element to be inserted: ";
    cin>>b;
    for(pos=0;pos<5;pos++)
        if(a[pos]>b)
            break;
    for(x=4;x>=pos;x--)
        a[x+1]=a[x];
    a[x+1]=b;
    cout<<"Now the array is: ";
    for(int i=0;i<6;i++)
        cout<<a[i]<<" ";
    return 0;
}
