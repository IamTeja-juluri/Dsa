class Solution {
public:
    
    unordered_map<long,int> memo;
    
    int minOperations(long n){
        
        if(n==1)
            return 0;
        if(memo.find(n)!=memo.end())
            return memo[n];
        if((n%2)==0)
         return memo[n]=1+minOperations(n/2);
         return memo[n]=1+min(minOperations(n-1),minOperations(n+1));
    }
    
    int integerReplacement(int n) {
        
        return minOperations(n);
    }
};
