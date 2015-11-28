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
        cout<<"\nStudent Menu\n1.Enter Records\n2.View Records\n3.Delete Record\n4.Exit\nPlease Enter your choice: ";
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
            if(!fin)
            {
                cout<<"Cannot open file!!!";
                break;
            }
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
            cout<<"Enter the Roll no that you want to delete : ";
            cin>>rno;
            ifstream fin("student.txt",ios::in|ios::binary);
            ofstream fout("temp.txt",ios::out|ios::binary);
            int flag=1;
            while(!fin.eof())
            {
                Student stud;
                fin.read((char*)&stud,sizeof(stud));
                if(stud.getRollNo()!=rno)
                {
                    fout.write((char*)&stud,sizeof(stud));
                }
                else
                    flag=0;
                if(fin.eof())   break;
            }
            fin.close();
            remove("student.txt");
            rename("temp.txt","student.txt");
            if(flag==1)
                cout<<"Student Record Not found!!";
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
