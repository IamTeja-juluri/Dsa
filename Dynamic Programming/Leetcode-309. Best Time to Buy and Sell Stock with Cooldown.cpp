class Solution {
public:
    
    vector<vector<int> > dp;
    
    int helper(vector<int>&prices,int idx,int mask){
        
        if(idx>=prices.size())
            return 0;
        
        if(dp[idx][mask]!=-1)
            return dp[idx][mask];
        
        int curr_price=prices[idx];
        
        if(mask==0){ //mask=0 --> buy a stock
            
            int op1=-prices[idx]+helper(prices,idx+1,!mask);
            int op2=helper(prices,idx+1,mask);
            
            return dp[idx][mask]=max(op1,op2);
        }
        
        else{ //mask=1 -->sell a stock
            
            int op1=prices[idx]+helper(prices,idx+2,!mask);
            int op2=helper(prices,idx+1,mask);
             
            return dp[idx][mask]=max(op1,op2);
                
        }
       
            return 0;
    }    
    
    int maxProfit(vector<int>& prices) {
     
        int n=prices.size();
        dp.resize(n,vector<int>(2,-1));
        
        return helper(prices,0,0);
        
    }
};
