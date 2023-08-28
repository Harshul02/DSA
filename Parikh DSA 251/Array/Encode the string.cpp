#include <bits/stdc++.h> 
string encode(string &s)
{
    //   Write your code here.
    int n = s.size();
    int count = 1;
    string str = "";
    for(int i= 0 ; i<n; i++)
    {
        if(s[i] == s[i+1])
            count++;
        else{
            str += s[i] + to_string(count);
            count = 1;
        }
    }
    return str;
}