string interpret(string c) {
        string s = "";
        for(int i=0; i<c.length() -1; i++)
        {
            if(c[i]=='(' and c[i+1] == ')'){
                s += "o";
                i++;
            }
            else if(c[i] == 'G')
                s += "G";
            else{
                s+= "al";
                i+=3;
            }
        }
        if(c[c.length() -1] == 'G')
            s+="G";
        return s;
    }