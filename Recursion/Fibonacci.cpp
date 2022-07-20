#include<iostream>
using namespace std;

int F[10];

int fib(int n)
{
    int a=0,b=1,s=0,i;
    if(n<=1)
    return n;
    
    for(i=2; i<=n; i++)
    {
        s=a+b;
        a=b;
        b=s;
    }
    return s;
}


int fib1(int n)
{
    if(n<=1)
    return n;
    
    return fib(n- 2)+fib(n- 1);
}

int fib2(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    if(F[n-2]==-1)
        F[n-2]=fib2(n-2);
    if(F[n-1]==-1)
        F[n-1]=fib2(n-1);
        
    return F[n-2]+F[n-1];
}
int main()
{
    for(int i=0;i<10; i++)
    {
        F[i]=-1;
    }
    cout<<fib2(6);
}