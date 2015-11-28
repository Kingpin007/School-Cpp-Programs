#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
char t[2];
using namespace std;
class Employee
{
    char address[100];
    double salary;
    int position,noofsales;
public:
    char employeename[80];
    void setname(char a[80],int size)
    {
        for(int i=0;i<size;i++)
            employeename[i]=a[i];
    }
    void setsalary(double sal)
    {
        salary=sal;
    }
    void setposition(int pos)
    {
        position=pos;
    }
    void setsales(int sales)
    {
        noofsales=sales;
    }
    void setaddress(char b[100],int size)
    {
        for(int i=0;i<size;i++)
            address[i]=b[i];
    }
    void displaydatahandler()
    {
        cout<<"Display\n1.Name of Employee\n2.Salary\n3.Position\n4.Sales\n5.Address\n6.All \nEnter Your Choice: ";
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Name: "<<employeename<<endl; break;
        case 2:
            cout<<"Salary: Rs."<<salary<<endl;  break;
        case 3:
            cout<<"Position: "<<position<<endl; break;
        case 4:
            cout<<"Sales: "<<noofsales<<endl;   break;
        case 5:
            cout<<"Address: "<<address<<endl;   break;
        case 6:
            cout<<"\nName: "<<employeename<<"\nSalary : Rs."<<salary<<"\nPosition : "<<position<<"\nSales: "<<noofsales<<"\nAddress : "<<address<<endl;
            break;
        default:
            cout<<"Wrong Input!!";
        }
    }
};
 Employee ob[10];
int main()
{
    int x;
    char name[80],address[100];
    double sal;
    cout<<"How many employees do you have : ";
    int emp,position,sales;
    cin>>emp;
    cout<<"You will now enter the details: "<<endl;
    for(int i=0;i<emp;i++)
    {
        cout<<"Enter name of employee "<<i+1<<" : ";
        gets(t);
        gets(name);
        cout<<"Enter address of Employee: "<<i+1<<" : ";
        gets(address);
        for(x=0;name[x]!='\0';x++);
        ob[i].setname(name,x);
        for(x=0;address[x]!='\0';x++);
        ob[i].setaddress(address,x);
        cout<<"Enter Position, salary and no. of sales: ";
        cin>>position>>sal>>sales;
        ob[i].setsalary(sal);
        ob[i].setsales(sales);
        ob[i].setposition(position);
    }
    cout<<"You have now succesfully entered all the details"<<endl;
    cout<<"\nEnter Employee name to get details ";
    gets(t);
    gets(name);
    int z=0;
    while(z<10)
    {
        int flag=0;
        for(int j=0;name[j]!='\0';j++)
        {
            if(ob[z].employeename[j]!=name[j])
            {
                flag = 1;
                break;
            }
        }
        z++;
        if(flag==0)
            break;
    }
    if(z>=9)
        cout<<"Name not found!";
    else
    {
        cout<<"\nFound Employee "<<name<<endl;
        z--;
        ob[z].displaydatahandler();
    }
    return 0;
}
