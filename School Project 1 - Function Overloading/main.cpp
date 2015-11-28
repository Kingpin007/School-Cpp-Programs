#include <iostream>

using namespace std;

int greatest(int a, int b)
{
    return(a>b?a:b);
}
int greatest(int a,int b,int c)
{
    int grt=a;
    if(b>a)
        grt=b;
    if(c>grt)
        grt=c;
    return grt;
}
int main()
{
    int choice;
    cout << "1.Find greatest of 2 numbers\n2.Find Greatest of 3 numbers\nEnter your choice: ";
    cin>>choice;
    if(choice==1)
    {
        cout<<"\nEnter 2 numbers: ";
        int a,b;
        cin>>a>>b;
        cout<<"The greatest of the two is: "<<greatest(a,b);
    }
    else if(choice==2)
    {
        cout<<"\nEnter 3 numbers: ";
        int a,b,c;
        cin>>a>>b>>c;
        cout<<"The greatest of the three is: "<<greatest(a,b,c);
    }
    else
        cout<<"Error wrong input!!!";
    return 0;
}
