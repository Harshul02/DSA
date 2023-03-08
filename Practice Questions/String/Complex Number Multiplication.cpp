string complexNumberMultiply(string num1, string num2) {
        int ra,ia,rb,ib;
        char buff;
        stringstream aa(num1), bb(num2), ans;
        aa>>ra>>buff>>ia>>buff;
        bb>>rb>>buff>>ib>>buff;
        ans<<ra*rb - ia*ib<<"+"<<ra*ib + rb*ia<<"i";
        return ans.str();
    }