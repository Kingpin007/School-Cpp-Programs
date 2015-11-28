#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main()
{
    ofstream fout("file.txt",ios::app);
    char s[80],ch;
    do
    {
        cout<<"Enter the line to be entered in the file: ";
        cin.getline(s,80);
        fout<<s<<"\n";
        cout<<"Want to enter more (y/n) : ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fout.close();
    ifstream fin("file.txt");
    cout<<"\n\nThe file now contains: \n\n";
    while(!fin.eof())
    {
        char line[80];
        fin.getline(line,80);
        if(fin.eof()) break;
        cout<<line<<endl;
    }
    return 0;
}
