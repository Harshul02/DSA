#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int,int> &a, pair<int,int> &b)
{
    return(a.second<b.second);
}

int main()
{
    int n;
    cin>>n;
    int s[n];
    int f[n];
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>f[i];
    }
    for(int i=0; i<n; i++)
    {
        v.push_back({s[i],f[i]});
    }
    sort(v.begin(), v.end(),comp);
    cout << "activities selected are "<<endl;
    int i = 0;
    cout << "(" << v[i].first << ", " << v[i].second << "), ";
    for (int j = 1; j < n; j++)
    {
      if (v[j].first >= v[i].second)
      {
          cout << "(" << v[j].first << ", "
              << v[j].second << "), ";
          i = j;
      }
    }
    return 0;
}