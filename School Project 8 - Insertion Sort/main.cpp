#include <iostream>

using namespace std;

int main()
{
    int a[5];
    cout<<"Enter 5 elements of the integer arrray: ";
    for(int i=0;i<5;i++)
        cin>>a[i];
    for(int j=1;j<5;j++)
    {
        int key=a[j];
        int i=j-1;
        while(i>=0&&a[i]>key)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
    cout<<"The sorted arrays is: \n";
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    return 0;
}
