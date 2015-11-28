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
    int a[6],min1,pos,tmp;
    cout<<"Enter 5 elements of the array: ";
    for(int i=0;i<5;i++)
        cin>>a[i];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(a[j+1]<a[j])
            {
                int tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
    cout<<"Now the array is: ";
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    return 0;
}
