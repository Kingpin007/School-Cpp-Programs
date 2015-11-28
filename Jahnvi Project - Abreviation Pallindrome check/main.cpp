#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

int main()
{
    char line1[80],line2[80];
    int i,j;
    cout << "Input String: ";
    gets(line1);
    for(i=0,j=1;line1[i]!='\0';i++)
    {
        if((i==0)&&isalpha(line1[i]))
        {
            line2[i]=line1[i];
        }
        if(line1[i]==' ')
            {

                line2[j]=line1[i+1];
                j++;
            }
    }
    cout<<line2;
    return 0;
}
