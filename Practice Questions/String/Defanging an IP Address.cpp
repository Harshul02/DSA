string defangIPaddr(string address) {
        // for(auto it : address)
        // {
        //     if(it == '.')
        //     {
        //         s += "[.]";
        //     }
        //     else s+= it;
        // }
        // return s;
        
        regex r("[.]");
        return regex_replace(address, r, "[.]");
    }