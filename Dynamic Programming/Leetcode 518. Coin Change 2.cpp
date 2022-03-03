class Solution {
public:
    
    vector<vector<int>> dp;
    
    int totalWays(vector<int>&coins,int amount,int n){
        
      
        if(amount==0){
            return 1;
        }
        
        if(n==0){
            return 0;
        }
        
        if(dp[n-1][amount]!=-1){
            return dp[n-1][amount];
        }
        
        if(coins[n-1]>amount){
            return dp[n-1][amount]=totalWays(coins,amount,n-1);
        }
        
        return dp[n-1][amount]=totalWays(coins,amount-coins[n-1],n)+totalWays(coins,amount,n-1);
        
        
    }
    
    
    
    int change(int amount, vector<int>& coins) {
        
        int len=coins.size();
        
        dp.resize(len,vector<int>(amount+1,-1));
        
        return totalWays(coins,amount,len);
        
    }
};
