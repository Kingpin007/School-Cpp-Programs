#include <iostream>

using namespace std;
int *rollno;
float *marks;
int main()
{
    int size,i;
    cout<<"How many elements are there in the array?";
    cin>>size;
    rollno = new int[size];
    marks = new float[size];
    if ((!rollno)||(!marks))
    {
        cout<<"Out Of Memory";
        return 1;
    }
    for(i = 0; i< size; i++)
    {
        cout<<"Enter roll no and marks for student"<<i+1<<"\n";
        cin>>rollno[i]>>marks[i];
    }
    for(i=0;i<size;i++)
    {
        cout<<"Roll No and Marks of student"<<i+1<<"is:";
        cout<<rollno[i]<<endl<<marks[i];
    }
    delete[] marks;
    delete[] rollno;
    return 0;
}
