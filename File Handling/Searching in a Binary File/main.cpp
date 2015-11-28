#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
class Student
{
    int RollNo,Class;
    char Name[40];
public:
    Student(int r=0,int c=0,char *name="NULL")
    {
        RollNo=r;
        Class=c;
        strcpy(Name,name);
    }
    int getRollNo()
    {
        return RollNo;
    }
    char *getName()
    {
        return Name;
    }
    void display()
    {
        cout<<"Roll No: "<<RollNo<<"\tClass: "<<Class<<"\nName: "<<Name<<endl;
    }
};
int main()
{
    int rno,cls,choice;
    char name[40];
    ofstream fout("student.txt",ios::out|ios::binary|ios::app);
    char ch='y',ch2='y';
    while(ch2=='y'||ch2=='Y')
    {
        cout<<"\nStudent Menu\n1.Enter Records\n2.View Records\n3.Search for records\n4.Exit\nPlease Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            while(ch=='y'||ch=='Y')
            {
                cout<<"Enter Roll No and Class : ";
                cin>>rno>>cls;
                cout<<"Enter Name: ";
                cin>>name;
                Student stud(rno,cls,name);
                fout.write((char*)&stud,sizeof(stud));
                cout<<"Want to enter more records (y/n): ";
                cin>>ch;
            }
            fout.close();
        }   break;
        case 2:
        {
            ifstream fin("student.txt",ios::in|ios::binary);
            while(!fin.eof())
            {
                Student stud1;
                fin.read((char*)&stud1,sizeof(stud1));
                if(fin.eof())   break;
                stud1.display();
            }
            fin.close();
        }    break;
        case 3:
        {
            cout<<"Enter the Roll no that you want to search for : ";
            cin>>rno;
            ifstream fin1("student.txt",ios::in|ios::binary);
            while(!fin1.eof())
            {
                Student stud1;
                fin1.read((char*)&stud1,sizeof(stud1));
                if(stud1.getRollNo()==rno)
                {
                    cout<<"Student Record found!! Details are:\n";
                    stud1.display();
                    system("pause");
                    break;
                }
                if(fin1.eof())   break;
            }
            if(fin1.eof())
                cout<<"Student Record Not found!!";
            fin1.close();
        }   break;
        case 4:
            break;
        default:
            cout<<"Wrong input!!";
        }
        cout<<"\nWant to go back to menu (y/n) : ";
        cin>>ch2;
    }
    return 0;
}
