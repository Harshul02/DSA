#include<iostream>
using namespace std;

void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}

void Bubble(int A[], int n)
{
    int flag=0;
    for(int i=0; i<n-1; i++)
    {
        flag=0;
        for(int j=0; j<n-1-i; j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}

void Insertion(int A[], int n)
{
    int x,i,j;
    for(i=1; i<n; i++)
    {
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

void Selection(int A[], int n)
{
    int i,j,k;
    for(i=0; i<n-1; i++)
    {
        for(j=k=i; j<n; j++)
        {
            if(A[j]<A[k])
                k=j;
        }
        swap(&A[i], &A[k]);
    }
}

int Partition(int A[], int l, int h)
{
    int pivot=A[l];
    int i=l,j=h;
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);

        if(i<j)swap(&A[i], &A[j]);
    }while(i<j);

    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h)
{
    if(l<h)
    {
        int j=Partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

int main()
{
    int A[]={3,7,9,10,6,5,12,4,11,2,INT_MAX};
    int n=11;
    //Bubble(A,10);
    //Insertion(A,n);
    //Selection(A,n);
    QuickSort(A,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
