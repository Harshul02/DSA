#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void BFS(vector<vector<int>> &v, int start, int end)
{
    queue<int> q;
    int n=v[0].size();
    int visited[n]={0};
    int i=start;
    cout<<i+1<<" ";
    q.push(i);
    visited[i]=1;

    while(!q.empty())
    {
        i=q.front();
        q.pop();
        for(int j=0; j<n; j++)
        {
            if(v[i][j]==1 && visited[j]==0)
            {
                cout<<j+1<<" ";
                visited[j]=1;
                q.push(j);
            }
        }
    }

}

int main()
{
    vector<vector<int>> v;
    int n,val;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        vector<int> row;
        for(int j=0; j<n; j++)
        {
            cin>>val;
            row.push_back(val);
        }
        v.push_back(row);
    }
    int s,e;
    cin>>s>>e;
    BFS(v,s-1,e-1);
    return 0;
}
