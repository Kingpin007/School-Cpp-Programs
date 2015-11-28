#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
struct emp
{
    char name[30];
    int rno;
};
int main()
{
    emp a[10];
    int n;
    cout<<"Enter the number of employees whose details you want to enter: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Employee "<<i+1<<" name : ";
        cin>>a[i].name;
        a[i].rno=i+1;
    }
    cout<<"\n The details of the employees are\n";
    for(int i=0;i<n;i++)
        cout<<"\nRno : "<<a[i].rno<<"\nName: "<<a[i].name;
    cout<<"\nThe array will now be sorted according to name!\n";
    //Sorting algorith
    int i,j,z;
    for(i=1;i<n;i++)
    {
        emp key=a[i];
        int j=i-1;
        while(j>=0)
        {
            z=0;
            if(strcmp(a[j].name,key.name)!=0)
                while(a[j].name[z]==key.name[z])
                    z++;
            if((a[j].name[z]>key.name[z]))
            {
                a[j+1]=a[j];
            }
            j--;
        }
        a[j+1]=key;
    }
    cout<<"\n The details of the employees are\n";
    for(int i=0;i<n;i++)
        cout<<"\nRno : "<<a[i].rno<<"\nName: "<<a[i].name;
    return 0;
}
