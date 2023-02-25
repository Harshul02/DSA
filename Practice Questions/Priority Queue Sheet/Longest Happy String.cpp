string longestDiverseString(int a, int b, int c) {
        int total = a+b+c;
        int A = 0, B=0, C=0;
        string s = "";
        while(total-- > 0)
        {
            if((a>=b and a>=c and A!=2)|| (a>0 and (B==2 || C==2)))
            {
                s+="a";
                A++;
                a--;
                B=C=0;
            }
            else if((b>=a and b>=c and B!=2)|| (b>0 and (A==2 || C==2)))
            {
                s+="b";
                B++;
                b--;
                A=C=0;
            }
            else if((c>=b and c>=a and C!=2)|| (c>0 and (A==2 || B==2)))
            {
                s+="c";
                C++;
                c--;
                B=A=0;
            }
        }
        return s;
    }

// Logic
/*
in this, we get a,b,c as input.
we initialize A=0, B=0, C=0 to check which is in continuation
total = a+b+c;
inside while loop 
we check the number with max value and it is not int continuation of 2
1) a>=b and a>=c and A!=2
we also checked if one of the remaining two is already used and value of a <b or <c
2) a>0 and (B==2 || C==2)

=> s += "a";
a--;   //decreased the value so that now maximum that most "a" can be used
A++;    // incremented to check which is currently 2
B=C=0;  // B=C=0 so that we can use "b" or "c"
*/