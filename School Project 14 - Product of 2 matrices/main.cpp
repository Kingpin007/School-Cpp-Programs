#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int a[5][5],b[5][5],c[5][5],i,j,m,n,p,q,ip;
    cout<<"Input row and column of matrix a: ";
    cin>>m>>n;
    cout<<"Input row and column of matrix b: ";
    cin>>p>>q;
    if(n!=p)
        cout<<"Matrices cannot be multiplied!!";
    cout<<"Input Matrix a: \n";
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    cout<<"Input Matrix b: \n";
    for(i=0;i<p;i++)
        for(j=0;j<q;j++)
            cin>>b[i][j];
    cout<<"\nProduct of matrices A and B is :\n";
    for(i=0;i<m;i++)
    {
        cout<<endl;
        for(j=0;j<q;j++)
        {
            c[i][j]=0;
            for(ip=0;ip<n;ip++)
                c[i][j]+=(a[i][ip]*b[ip][j]);
            cout<<c[i][j]<<" ";
        }
    }
    return 0;
}
