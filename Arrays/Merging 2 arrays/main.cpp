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
    for(;z<10;z++)
    {
        min1=a1[x];
        min2=a2[y];
        if(min1<=min2 || y>4)

        {
            b[z]=min1;
            x++;
        }
        else
        {
            b[z]=min2;
            y++;
        }
    }
    for(int i=0;i<10;i++)
        cout<<b[i]<<" ";
    return 0;
}
