#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char line[50];
    cout<<"Enter a line of text: ";
    gets(line);
    int len=strlen(line);
    int i,j,last=0;
    for(i=0;i<len;)
    {
        j=i;
        while(line[j]!=' '&&line[j]!='\0')
            j++;
        last=j;
        if(j%2==0)
            last=j;
        else
            last=j-1;
        char ch1;
        for(int k=i;k<last;k+=2)
        {
            ch1=line[k];
            line[k]=line[k+1];
            line[k+1]=ch1;
        }
        i=j+1;
    }
    cout<<line<<endl;
    return 0;
}
