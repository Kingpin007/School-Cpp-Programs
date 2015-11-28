#include <iostream>

using namespace std;

int main()
{
    int a[5],b,runs=0;
    cout<<"Enter 5 elements of the array(in ascending order): ";
    for(int i=0;i<5;i++)
        cin>>a[i];
    cout<<"Enter Element to me searched for: ";
    cin>>b;
    int beg=0,mid,last=5;
    while(beg<=last)
    {
        mid=(beg+last)/2;
        if(a[mid]==b)
        {
            cout<<b<<" found at "<<mid+1;
            break;
        }
        else if(a[mid]>b)
        {
            last=mid-1;
        }
        else if(a[mid]<b)
        {
            beg=mid+1;
        }
        if(runs>40)
        {
            cout<<"Element not found!!";
            break;
        }
        runs++;
    }
    return 0;
}
