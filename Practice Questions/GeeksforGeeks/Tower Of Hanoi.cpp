void tower(int n, int a, int b, int c)
    {
        if(n==0) return;
        
        tower(n-1, a, c, b);
        cout<<"move disk "<<n<<" from rod "<<a<<" to rod "<<b<<endl;
        tower(n-1, c, b, a);
    }
    
    long long toh(int n, int from, int to, int aux) {
        // Your code here
        tower(n, from, to, aux);
        return pow(2,n)-1;
    }

// TC = O(2^n)
// SC = O(n)