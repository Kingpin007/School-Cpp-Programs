#include <iostream>

using namespace std;

int main()
{
    int a[5],b;
    cout<<"Enter 5 elements of the array: ";
    for(int i=0;i<5;i++)
        cin>>a[i];
    cout<<"Enter Element to me searched for: ";
    cin>>b;
    for(int i=0;i<5;i++)
    {
        if(a[i]==b)
        {
             cout<<b<<" found at : "<<i+1;
             break;
        }
        else if(i==4)
            cout<<b<<" not found!!";
    }
    return 0;
}
