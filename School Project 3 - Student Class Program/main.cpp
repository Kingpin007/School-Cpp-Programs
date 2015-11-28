#include <iostream>
#include <cstdio>
#include <cstdlib>
char t[2];
using namespace std;
class Student
{
private:
    int rollno;
    char grade,name[25];
    float marks;
public:
    void readStudent()
    {
        cout<<"Enter Roll no. :";   cin>>rollno;
        cout<<"Enter name: ";       gets(t);gets(name);
        cout<<"Enter Marks: ";      cin>>marks;
    }
    void dispStudent()
    {
        calcGrade();
        cout<<"Roll No: "<<rollno<<"\nName: "<<name<<"\nMarks: "<<marks<<"\nGrade: "<<grade<<endl;
        system("pause");
    }
    int getRollNo()
    {
        return rollno;
    }
    int getMarks()
    {
        return marks;
    }
    void calcGrade()
    {
        if(marks>=75)
            grade='A';
        else if(marks>=60)
            grade='B';
        else if(marks>=50)
            grade='C';
        else if(marks>=40)
            grade='D';
        else
            grade='F';
    }
};
int main()
{
    Student a[3];
    int i=0;
    for(i=0;i<3;i++)
    {
        cout<<"Enter details of Student\n";
        a[i].readStudent();
    }
    int choice,rno,pos=-1,highmarks=0;
    do
    {
        system("cls");
        cout<<"\nMain Menu\n"<<"1.Specific Student\n2.Topper\n3.Exit\nEnter Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter Roll no: ";
            cin>>rno;
            for(i =0;i<3;i++)
            {
                if(a[i].getRollNo()==rno)
                {
                    a[i].dispStudent();
                    break;
                }
            }
            if(i==10)
                cout<<"Invalid Input!!"<<endl;
            break;
        case 2:
            for(i=0;i<3;i++)
            {
                if(a[i].getMarks()>highmarks)
                {
                    pos=i;highmarks=a[i].getMarks();
                }
            }
            a[pos].dispStudent();
            break;
        case 3:
            break;
        default:
            cout<<"\nWrong Choice!!\n";
                break;
        }
    }while(choice>=1&&choice<3);
    return 0;
}
