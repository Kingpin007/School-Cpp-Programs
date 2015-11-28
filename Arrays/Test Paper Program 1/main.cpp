#include <iostream>

using namespace std;

int main()
{
    cout << "Input Array Size: " << endl;
    int n,a[30],temp1,temp2,temp3;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Arrays entered is: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"Changing array..."<<endl;
    temp3=a[n-1];
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            temp1=a[i+1];
            a[i+1]=a[i];
        }
        else
        {
            temp2=a[i+1];
            a[i+1]=temp1;
            temp1=temp2;
        }
    }
    a[0]=temp3;
    cout<<"\nThe new array is\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
