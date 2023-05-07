int titleToNumber(string col) {
        int result = 0;
        for(char c : col)
        {
            int d = c - 'A' + 1;
            result = result * 26 + d;
        }
        return result;
    }