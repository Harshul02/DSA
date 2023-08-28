#include <bits/stdc++.h> 
int minimumParentheses(string s) {
    // Write your code here.
    // pattern is the given string.
    int n = s.size();
    // stack<char> st;
    // int cnt = 0;
    // for(int i = 0 ;i<n; i++)
    // {
    //     if(s[i] == '(')
    //         st.push(s[i]);
    //     else if(s[i] == ')' and st.empty())
    //         cnt++;
    //     else 
    //         st.pop();
    // }
    // return st.size() + cnt;
    int cnt = 0;
    int i = 0;
    while(s[i] == ')')
    {
        cnt++;
        i++;
    }
    int total = 0;
    for(i; i<n; i++)
    {
        if(s[i] == '(')
            total++;
        else{
            if(total > 0)
                total--;
            else{
                cnt++;
            }
        }
    }
    return cnt + total;
}