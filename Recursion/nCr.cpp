#include <iostream>
using namespace std;

int fact(int n)
{
    if(n==0)
    return 1;
    
    return fact(n-1)*n;
}

int nCr(int n, int r)
{
    int a,b,c;
    a=fact(n);
    b=fact(r);
    c=fact(n-r);
    
    return a/(b*c);
}

int recnCr(int n, int r)
{
    if(r==0|| n==r)
        return 1;
    return recnCr(n-1, r-1)+recnCr(n-1,r);
}

int main()
{
    cout<<recnCr(4,2);

    return 0;
}
