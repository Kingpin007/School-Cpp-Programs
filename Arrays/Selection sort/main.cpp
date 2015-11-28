#include <iostream>

using namespace std;

int main()
{
    int a[6],min1,pos,tmp;
    cout<<"Enter 5 elements of the array: ";
    for(int i=0;i<5;i++)
        cin>>a[i];
    for(int i=0;i<4;i++)
    {
        min1=a[i];
        pos=i;
        for(int j=i+1;j<5;j++)
        {
            if(a[j]<min1)
            {
                min1=a[j];
                pos=j;
            }
            tmp=a[i];
            a[i]=a[pos];
            a[pos]=tmp;
        }
    }
    cout<<"Now the array is: ";
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    return 0;
}
