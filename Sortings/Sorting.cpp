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

void Merge(int A[], int l, int mid, int h)
{
    int i=l,j=mid+1,k=l;
    int B[100];

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for(; i<=mid; i++)
        B[k++]=A[i];
    for(; j<=h; j++)
        B[k++]=A[j];

    for(i=l; i<=h; i++)
    {
        A[i]=B[i];
    }
}

void IMergeSort(int A[], int n)
{
    int p,i,l,mid,h;

    for(p=2; p<=n; p=p*2)
    {
        for(int i=0; i+p-1<n; i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n)
        Merge(A,0,p/2-1,n-1);
}

void MergeSort(int A[], int l, int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

int main()
{
    int A[]={3,7,9,10,6,5,12,4,11,2};
    int n=10;
    //Bubble(A,10);
    //Insertion(A,n);
    //Selection(A,n);
    //QuickSort(A,0,n-1);
    //IMergeSort(A,n);
    MergeSort(A,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
