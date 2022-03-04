class Solution {
public:
    
    vector<int> dp;
    
    int findMinCost(vector<int>&cost,int idx){
        
        if(idx>=cost.size()){
            return 0;
        }
        
        if(dp[idx]!=-1) return dp[idx];
        
        return dp[idx]=cost[idx]+min(findMinCost(cost,idx+1),findMinCost(cost,idx+2));
        
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        dp.resize(cost.size(),-1);
        
        return min(findMinCost(cost,0),findMinCost(cost,1));
    }
};
