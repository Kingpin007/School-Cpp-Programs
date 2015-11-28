#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
class Travel
{
    char TravelCode[5];
    int NoofAdults,NoofChildren,distance;
    double TotalFare;
public:
    Travel()
    {
        strcpy(TravelCode,"NULL");
        NoofAdults=NoofChildren=distance=TotalFare=0;
    }
    void AssignFare()
    {
        double fare=0;
        if(distance>=1000)
            fare=(NoofAdults*500)+(NoofChildren*250);
        else if(distance>=500)
            fare=(NoofAdults*300)+(NoofChildren*100);
        else
            fare=(NoofAdults*200)+(NoofChildren*100);
        TotalFare=fare;
    }
    void EnterTravel()
    {
        cout<<"Enter Travel Code: ";
        cin>>TravelCode;
        cout<<"Enter no. of adults and Children respectively : ";
        cin>>NoofAdults>>NoofChildren;
        cout<<"Enter Distance: ";
        cin>>distance;
        AssignFare();
    }
    void ShowTravel()
    {
        cout<<"Travel Code: "<<TravelCode<<"\nNo of Adults: "<<NoofAdults<<"\nNo of children: "<<NoofChildren<<"\nDistance: "<<distance<<"\nFare: "<<TotalFare<<endl;
    }
};
int main()
{
    Travel t;
    t.EnterTravel();
    t.ShowTravel();
    return 0;
}
