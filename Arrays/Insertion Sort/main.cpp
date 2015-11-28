#include <iostream>

using namespace std;
void Swap(int &a,int &b)
{
    int tmp=a;
    a=b;
    b=a;
}
int main()
{
    int a[6];
    cout<<"Enter 5 elements of the array: ";
    for(int i=0;i<5;i++)
        cin>>a[i];
    for(int i=1;i<5;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0&&key<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    cout<<"Now the array is: ";
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    return 0;
}
