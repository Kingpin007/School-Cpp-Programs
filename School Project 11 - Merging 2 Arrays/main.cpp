#include <iostream>

using namespace std;

int main()
{
    int a1[5],a2[5],b[10];
    cout << "Input 5 elements of array 1(in ascending order) : " << endl;
    for(int i=0;i<5;i++)
        cin>>a1[i];
    cout << "Input 5 elements of array 2(in ascending order) : " << endl;
    for(int i=0;i<5;i++)
        cin>>a2[i];
    int min1,min2;
    int x=0,y=0,z=0;
    for(;y<10;y++)
    {
        min1=a1[x];
        min2=a2[z];
        if(min1<=min2 || z>4)

        {
            b[y]=min1;
            x++;
        }
        else
        {
            b[y]=min2;
            z++;
        }
    }
    for(int i=0;i<10;i++)
        cout<<b[i]<<" ";
    return 0;
}
