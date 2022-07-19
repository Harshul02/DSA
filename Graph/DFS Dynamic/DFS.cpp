#include<iostream>
#include<vector>
using namespace std;

void DFS(vector<vector<int>> &v, int start, int n)
{
    int x=v[0].size();
    int visited[x]={0};
    cout<<endl<<endl;
    if(visited[start]==0)
    {
        cout<<start+1<<" ";
        visited[start]=1;
        for(int j=0; j<n; j++)
        {
            if(v[start][j]==1 && visited[j]==0)
                DFS(v,j,n);
        }
    }
}

int main()
{
    int sz;
    cin>>sz;
    vector<vector<int>> v;
    int x;
    for(int i=0; i<5; i++)
    {
        vector<int> s;
        for(int j=0; j<5; i++)
        {
            cin>>x;
            s.push_back(x);
        }
        v.push_back(s);
    }
        int start,end;
        cin>>start>>end;
        DFS(v,start-1,end-1);
        // return 0;
}