#include <iostream>
#include <cstdio>
using namespace std;
char *match(char c, char *s)
{
    while((c!=*s)&&(*s))
        s++;
    return s;
}
int main()
{
    char str[80],*cp,ch;
    cout<<"Enter a string: ";
    gets(str);
    cout<<"Enter the character: ";
    cin>>ch;
    cp=NULL;
    cp=match(ch,str);
    if(*cp)
    {
        cout<<endl;
        for(;*cp!='\0';cp++)
            cout<<*cp;
    }
    else
        cout<<"No match found!!";
    cout<<endl;
    return 0;
}
