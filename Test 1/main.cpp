#include <iostream>

using namespace std;
struct Node
{
    int info;
    Node *next;
}*save;
int main()
{
    cout << sizeof(save) << endl;
    return 0;
}
