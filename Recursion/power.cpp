#include<iostream>
using namespace std;

int pow(int m,int n)
{
    if(n==0)
    return 1;

    return pow(m,n-1)*m;
}

int main()
{
    int n,m;
    cout<<"Input m and n  (m)^n: ";
    cin>>m>>n;
    cout<<"(m)^n: "<<pow(m,n);
}