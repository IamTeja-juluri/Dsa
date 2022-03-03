class Solution {
public:
    vector<vector<int>>dp;
    int minCost(vector<vector<int>>&nums,int i,int j){
        
        int n=nums.size();
        
        if(i>=n || j<0 || j>=nums[i].size()){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]=nums[i][j]+min(minCost(nums,i+1,j),minCost(nums,i+1,j+1));
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        dp=vector<vector<int>>(triangle.size(),vector<int>(triangle.size(),-1));
        return minCost(triangle,0,0);
    }
};