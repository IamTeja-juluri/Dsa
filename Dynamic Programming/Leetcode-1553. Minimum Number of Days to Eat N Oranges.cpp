class Solution {
public:
    //tc:logn
    map<int,int> mp; // using maps to avoid tle
    
    int helper(int n){
        
        if(n==0)
            return 0;
        
        if(n==1)
            return 1;
        
        if(mp.find(n)!=mp.end())
            return mp[n];
        
        // int op1=1+helper(n-1); gives runtime error cause it takes n number of calls
        // for op2=n becomes n-n/2 = n/2;
        // for op3=n becomes n-2n/3 = n/3;
        //now the prob reduces to making n divisible by 2 or 3
        
        return mp[n]=1+min( n%2 + helper(n/2) , n%3 + helper(n/3) );
    }
    
    
    int minDays(int n) {
        
        return helper(n);
    }
};
