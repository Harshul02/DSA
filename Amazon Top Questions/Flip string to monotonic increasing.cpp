class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt = 0, one = 0;
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == '1')
            {
                one++;
            }
            if(s[i] == '0' and one > 0)
                cnt++;

            cnt = min(cnt, one);
        }
        return cnt;
    }
};