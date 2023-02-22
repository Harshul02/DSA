int largestInteger(int num) {
        priority_queue<int> odd, even;
        string s = to_string(num);
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            if((s[i]-'0')%2==0)
                even.push(s[i] - '0');
            else odd.push(s[i] - '0');
        }

        int answer = 0;
        for(int i=0; i<n; i++)
        {
            answer = answer*10;
            if((s[i]-'0')%2 == 0){
                answer += even.top();
                even.pop();
            }
            else{
                 answer += odd.top();
                odd.pop();
            }
        }
        return answer;
    }