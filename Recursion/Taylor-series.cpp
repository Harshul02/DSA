#include<iostream>
using namespace std;

double e(int x,int n)
{
    static double p=1, f=1;
    double r;
    if(n==0)
    {
        return 1;
    }
   
        r=e(x,n-1);
        p=p*x;
        f=f*n;
        return r+p/f;
}

double e1(int x,int n)          //using Horner's Rule
{
    static double s=1;
    if(n==0)
        return s;
    s=1+s*x/n;
    return e1(x,n-1);
}

double e2(int x,int n)          //Iterative version
{
    double s=1;
    for(; n>0; n--)
    {
        s= 1+s*x/n;
    }
    return s;
}

int main()
{
    cout<<e(1,10);
}