#include<iostream>
#include<vector>
using namespace std;

int min(int a[], bool b[], int x)
{
    int min=INT_MAX, n;
    for(int i=0; i<x; i++)
    {
        if(b[i]==false && a[i]<min)
        {
            min=a[i];
            n=i;
        }
    }
    return n;
}

void Dijkstra(vector<vector<int>> &v, int s)
{
    int n=v[0].size();
    int dist[n];
    bool sptset[n];

    for(int i=0; i<n; i++)
    {
        dist[i]=INT_MAX;
        sptset[i]=false;
    }
    dist[s]=0;
    for(int i=0; i<n-1; i++)
    {
        int u=min(dist,sptset,n);
        sptset[u]=true;
        for (int j = 0; j < n; j++)
         {   if (!sptset[j] && v[u][j] && dist[u] != INT_MAX && dist[u] + v[u][j] < dist[j])
                dist[j] = dist[u] + v[u][j];
         }
    }
    cout <<endl<<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < n; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
}


int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v;
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
    Dijkstra(v,0);
    return 0;
}