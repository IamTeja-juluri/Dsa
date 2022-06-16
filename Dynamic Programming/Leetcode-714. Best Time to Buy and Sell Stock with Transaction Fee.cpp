class Solution {
public:
    
    vector<vector<int> > dp;
    
    int helper(vector<int>&prices,int idx,int mask,int fee){
        
        if(idx>=prices.size())
            return 0;
        
        if(dp[idx][mask]!=-1)
            return dp[idx][mask];
        
        if(mask==0){
            int op1=-prices[idx]+helper(prices,idx+1,!mask,fee);
            int op2=helper(prices,idx+1,mask,fee);
            return dp[idx][mask]=max(op1,op2);
        }
        
        else{
            int op1=prices[idx]-fee+helper(prices,idx+1,!mask,fee);
            int op2=helper(prices,idx+1,mask,fee);
            return dp[idx][mask]=max(op1,op2);
        }
        
        return 0;
    }
    
    
    int maxProfit(vector<int>& prices, int fee) {
        
        
        int n=prices.size();
        dp.resize(n,vector<int>(2,-1));
        
        return helper(prices,0,0,fee);
    }
};
