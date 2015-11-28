#include <iostream>
#include <cstdlib>

using namespace std;
class A
{
public:
    void divide(int a,int b)
    {
        if(b==0)
            cout<<"Cannnot divide by 0!!"<<endl;
        else if((a%b)==0)
            cout<<"Divisibe!!";
        else
            cout<<"Not divisible!!";
    }
    void divide(int a)
    {
        if(isprime(a))
            cout<<a<<" is a prime number!!";
        else
            cout<<a<<" is not a prime number!!";
    }
private:
    int isprime(int a)
    {
        if(a==0||a==1)
            return 0;
        for(int j=2;j<a;j++)
        {
            if(a==2)
                return 1;
            else if((a%j)==0)
                return 0;
        }
        return 1;
    }
};
int main()
{
    A ob;
    int a,b;
    cin>>a>>b;
    ob.divide(a,b);
    ob.divide(a);
    return 0;
}
