int stoneGameVI(vector<int>& al, vector<int>& bob) {
        vector<vector<int>> v;
        int n = al.size();
        for(int i=0; i<n; i++)
        {
            v.push_back({al[i] + bob[i], al[i], bob[i]});
        }
        sort(v.begin(), v.end(), greater<>());

        int a=0, b=0;
        for(int i=0; i<n; i++)
        {
            if(i%2 == 0)
                a+=v[i][1];
            else{
                b += v[i][2];
            }
        }
        if(a==b)
            return 0;
        else if(a>b)
            return 1;
        return -1;
    }

// Logic
/*
let al = [1,3]
bob = [2,1];
they both knows values of each other

if alice takes 1
then bob can only takes 1
it means draw
but we will try to make alice win the game
so, if alice takes 3, it means we can think it as alice has 3 + 1 as bob cannot takes 1
so, with max sum we sort the vector and solve the question.
*/