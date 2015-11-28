#include <iostream>

using namespace std;

int main()
{
    char *name[3]={"chirag","vishal","anirudh"};
    for(int i=0;i<3;i++)
    {
        cout<<name[i]<<endl;
    }
    char *t;
    t = name[2];
    name[2]=name[0];
    name[0]=t;
        for(int i=0;i<3;i++)
    {
        cout<<name[i]<<endl;
    }
    return 0;

}
