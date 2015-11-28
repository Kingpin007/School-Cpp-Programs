#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
char t[2];
class Student
{
private:
    char name[40];
    int Class,RollNo;
    double marks;
public:
    void input()
    {
        cout<<"Enter Name: ";
        gets(t);
        gets(name);
        cout<<"Enter Class, Roll No. and Marks: ";
        cin>>Class>>RollNo>>marks;
    }
    void output()
    {
        cout<<"\nName: "<<name<<"\nClass: "<<Class<<"\nRoll No. : "<<RollNo<<"\nMarks: "<<marks;
    }
};
int main()
{
    char file[40];
    ofstream fout("student.txt",ios::binary|ios::app);
    Student stud;
    cout<<"How many students: ";
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        stud.input();
        fout.write(((char*)&stud),sizeof(stud));
    }
    Student stud2;
    cout<<"\nDisplaying Details in the file: ";
    fout.close();
    ifstream fin("student.txt",ios::binary);
    while(!fin.eof())
    {
        fin.read((char*)&stud2,sizeof(stud2));
        if(fin.eof())
            break;
        stud2.output();
    }
    return 0;
}
