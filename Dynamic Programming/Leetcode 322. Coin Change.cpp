class Solution {
public:
    
    vector<int>  dp;
    
    int minCoins(vector<int>&coins,int amount){
        
        int n=coins.size();
        
        if(amount==0){
            return dp[amount]=0;
        }
        
        
        if(dp[amount]!=-1){
            return dp[amount];
        }
        
        int ans=INT_MAX-1; //imp
        
        for(int i=0;i<n;i++){
          
          if(coins[i]<=amount){
              
             int subprob=1+minCoins(coins,amount-coins[i]);
             ans=min(ans,subprob);
          
          }  
            
       }
        
        return dp[amount]=ans;
        
    }    
    
    int coinChange(vector<int>& coins, int amount) {
       
        int n=coins.size();
        
        dp.resize(amount+1,-1);
        
          long long ans=minCoins(coins,amount);
        
          if(ans==INT_MAX-1) return -1;
        
        return ans;
        
    }
};
