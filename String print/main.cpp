#include <iostream>

using namespace std;

int main()
{
    char line[]="My Name Is Vishal";
    char *cptr;
    for(cptr = line; *cptr!='\0'; cptr++)
    {
        cout<<*cptr;
    }
    return 0;
}
