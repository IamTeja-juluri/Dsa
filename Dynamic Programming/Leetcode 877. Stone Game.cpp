class Solution {
public:
     vector<vector<int>> dp;
    
    int game(vector<int>&nums,int i,int j){
        
        if(i==j){
            return nums[i];
        }
        if(i>j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int l=nums[i]+min(game(nums,i+2,j),game(nums,i+1,j-1));
        int r=nums[j]+min(game(nums,i,j-2),game(nums,i+1,j-1));
        
        return dp[i][j]=max(l,r);
        
    }
    
    
    bool stoneGame(vector<int>& nums) {
        
          dp.resize(nums.size(),vector<int>(nums.size(),-1) );
        
        int p1score=game(nums,0,nums.size()-1);
        int p2score=accumulate(nums.begin(),nums.end(),0) -p1score;
        
        return p1score>p2score;
        
        
    }
};