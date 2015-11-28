#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
class stu
{
    int rollno;
    char name[25];
    char Class[4];
    float marks;
    char grade;
public:
    void getdata()
    {
        cout<<"Rollno: ";   cin>>rollno;
        cout<<"Name: ";     cin>>name;
        cout<<"Class: ";    cin>>Class;
        cout<<"Marks: ";    cin>>marks;
        if(marks>=75)   grade='A';
        else if(marks>=60)  grade='B';
        else if(marks>=50)  grade='C';
        else if(marks>=40)  grade='D';
        else    grade='F';
    }
    void putdata()
    {
        cout<<"RollNo: "<<rollno<<"\tName: "<<name<<"\nMarks: "<<marks<<"\tGrade: "<<grade<<endl;
    }
    int getrno()
    {
        return rollno;
    }
    void modify();
}s1, stud;
void stu::modify()
{
    cout<<"RollNo: "<<rollno<<"\tName: "<<name<<"\nMarks: "<<marks<<"\tGrade: "<<grade<<endl;
    cout<<"Enter new details. "<<endl;
    char nm[20]=" ",Cl[4]=" ";
    float mks;
    cout<<"New Name: ";
    cin>>nm;
    cout<<"New Class: ";
    cin>>Cl;
    cout<<"New Marks: ";
    cin>>mks;
    if(strcmp(nm,".")!=0)
        strcpy(name,nm);
    if(strcmp(Cl,".")!=0)
        strcpy(Class,Cl);
    if(mks!=-1)
        marks=mks;
}



int main()
{
    fstream fio("stu.dat",ios::in|ios::out|ios::binary);
    int rno;
    long pos;
    char found='f';
/*    ofstream fout("stu.dat",ios::binary);
    char ch='y';
    while(ch=='y'||ch=='Y')
    {
        s1.getdata();
        fout.write((char*)&s1,sizeof(s1));
        cout<<"\nWant to write more? : ";
        cin>>ch;
    }*/
  cout<<"Enter Roll no of student to me modified: ";
    cin>>rno;
    while(!fio.eof())
    {
        pos=fio.tellg();
        fio.read((char*)&s1,sizeof(s1));
        if(s1.getrno()==rno)
        {
            s1.modify();
            fio.seekg(pos);
            fio.write((char*)&s1,sizeof(s1));
            found='t';
            break;
        }
    }
    if(found=='f')
        cout<<"record not found!!";
    fio.seekg(0);
    cout<<"Now the file contains:\n";
    while(!fio.eof())
    {
        fio.read((char*)&stud,sizeof(stud));
        if(fio.eof()!=0)
            break;
        stud.putdata();
    }
    fio.close();
    return 0;
}
