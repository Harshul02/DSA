#include<iostream>
using namespace std;

int pow(int m,int n)
{
    if(n==0)
    return 1;

    return pow(m,n-1)*m;
}

int pow1(int m, int n)
{
    if(n==0)
    return 1;
    if(n%2==0)
    return pow(m*m, n/2);
    else
    return m*pow(m*m, (n-1)/2);
}

int main()
{
    int n,m;
    cout<<"Input m and n  (m)^n: ";
    cin>>m>>n;
    cout<<"(m)^n: "<<pow1(m,n);
}