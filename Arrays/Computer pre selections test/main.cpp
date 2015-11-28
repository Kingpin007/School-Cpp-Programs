#include <iostream>
#include <cctype>
using namespace std;
void Secret(char Msg[],int N)
{
    for(int c=0;Msg[c]!='\0';c++)
        if(c%2==0)
            Msg[c]=Msg[c]+N;
        else if(isupper(Msg[c]))
            Msg[c]=tolower(Msg[c]);
        else
            Msg[c]=Msg[c]-N;
}
int main()
{
    char Sms[]="rEPorTmE";
    Secret(Sms,2);
    cout<<Sms<<endl;
    return 0;
}
