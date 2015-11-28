#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char t[2];
class Automobile
{
protected:
    char fuel[15],engine[15],company[15];
public:
    Automobile()
    {
        cout<<"Enter Fuel Type: ";
        gets(fuel);
        cout<<"Enter Engine Name: ";
        gets(engine);
        cout<<"Enter Company: ";
        gets(company);
    }
};
class Car : public Automobile
{
protected:
    int wheels,doors;
    char AC;
public:
    Car()
    {
        cout<<"Enter no. of wheels: ";
        cin>>wheels;
        cout<<"Enter no. of doors: ";
        cin>>doors;
        cout<<"Does car have AC (y/n) : ";
        cin>>AC;
    }
    ~Car()
    {
        cout<<"No. of wheels: "<<wheels<<"\nNo. of doors: "<<doors<<"\nFuel : "<<fuel<<"\nEngine: "<<engine;
        cout<<"\nCompany: "<<company;
        if(AC=='Y'||AC=='y')
            cout<<"\nCar has AC";
        else
            cout<<"\nCar does not have AC";
    }
};
int main()
{
    Car C;
    return 0;
}
