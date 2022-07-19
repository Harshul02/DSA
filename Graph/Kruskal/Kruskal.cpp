#include<iostream>
#include<vector>
using namespace std;

int find(vector<int> &v, int x)
{
    while(v[x]!=x)
        x=v[x];
    return x;
}

void Union(vector<int> &v, int a, int b)
{
    int x=find(v,a);
    int y=find(v,b);
    v[x]=y;   
}

void kruskal(vector<vector<int>> &v)
{
    int n=v[0].size();
    int mincost=0;
    int edgecount=0;
    vector<int> parent(n);
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
    }
    while(edgecount<n-1)
    {
        int min=32767;
        int a=-1,b=-1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(find(parent,i)!=find(parent,j) && v[i][j]<min)
                {
                    min=v[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        Union(parent,a,b);
        cout<<edgecount++ <<" ("<<a<<","<<b<<") "<<min<<endl;
        mincost+=min;
    }
    cout<<endl<<mincost;
}

int main()
{
    vector<vector<int>> v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        vector<int> vec;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            vec.push_back(x);
        }
        v.push_back(vec);
    }
    kruskal(v);
    return 0;
}