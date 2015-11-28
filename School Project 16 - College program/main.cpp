#include <iostream>
#include <cstdio>
char t[2];
using namespace std;

class Person
{
    char name[25];
    int age;
public:
    void getPerson()
    {
        cout<<"Enter Name: ";
        gets(t);
        gets(name);
        cout<<"Enter age: ";
        cin>>age;
    }
    void displayperson()
    {
        cout<<"Name: "<<name<<"\tAge: "<<age<<endl;
    }
};
class Student : public Person
{
    int rollno;
    float average;
public:
    void readstudent()
    {
        getPerson();
        cout<<"Enter Roll number: ";    cin>>rollno;
        cout<<"Enter Average marks: ";  cin>>average;
    }
    void disprollno()
    {
        cout<<"Roll number: "<<rollno<<endl;
    }
    float getaverage()
    {
        return average;
    }
};
class GradStudent : public Student
{
    char subject[25];
    char working;
public:
    void readit()
    {
        readstudent();
        cout<<"Enter main subject: ";
        gets(t);
        gets(subject);
        cout<<"Working (y/n) : ";
        cin>>working;
    }
    char workstatus()
    {
        return working;
    }
    void displaysubject()
    {
        cout<<"Subject: "<<subject;
    }

};
int main()
{
    GradStudent grad[5];
    int i,year;
    double num_working=0,non_working=0,div1=0,total=0;
    double topscore=0,score,number;
    double w,nw;
    cout<<"Enter Year: ";
    cin>>year;
    for(i=0;i<2;i++)
    {
        cout<<"Enter details if graduate "<<i+1<<endl;
        grad[i].readit();
        total++;
        if((grad[i].workstatus())=='Y'||(grad[i].workstatus())=='y')
            num_working++;
        else
            non_working++;
        score=grad[i].getaverage();
        if(score>topscore)
        {
            topscore=score;
            number=i;
        }
        if(score>=60.0)
            div1++;
    }
    i=number;
    cout<<"\n\t\tReport for the Year "<<year<<endl<<"\t\t----------\nWorking Graduates : "<<num_working<<"\tNon Working graduates: "<<non_working<<"\n\tDetails of the Top Scorer\n";
    grad[i].displayperson();
    grad[i].displaysubject();
    nw = non_working/total*100;
    w = div1/total*100;
    cout<<"\nAverage Marks: "<<grad[i].getaverage()<<"\n\t"<<nw<<"% of the graduates this year are non working and\n"<<w<<"%are first divisioners\n";
    return 0;
}
