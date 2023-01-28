#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    //Union By Rank
    vector<int> rank,parent;

public:

DisjointSet(int n)
{
    rank.resize(n+1, 0);
    parent.resize(n+1);
    for(int i=0; i<=n; i++)
    {
        parent[i] = i;
    }
}

int findParent(int node)
{
    if(node == parent[node])
        return node;
    return findParent(parent[node]);
}

void unionByRank(int u, int v)
{
    int ulp_u = findParent(u) ;
    int ulp_v = findParent(v) ;

    if(ulp_u == ulp_v) return;

    if(rank[ulp_u] < rank[ulp_v]){
        parent[ulp_u] = ulp_v;
    }
    else if(rank[ulp_u] > rank[ulp_v]){
        parent[ulp_v] = ulp_u;
    }
    else{ // if rank of both is same
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;
    }
}
};

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    // is 3 and 7 belongs to the same component
    if(ds.findParent(3) == ds.findParent(7))
    {
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }

    ds.unionByRank(3,7);

    if(ds.findParent(3) == ds.findParent(7))
    {
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }

    return 0;
}