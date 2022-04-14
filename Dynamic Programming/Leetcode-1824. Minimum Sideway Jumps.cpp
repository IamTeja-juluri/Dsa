class Solution {
public:
    
    vector<vector<int> >dp;
    int minJumps(vector<int>&nums,int idx,int lane){
        
        if(idx==nums.size()-1)
            return 0;
        
        if(dp[idx][lane]!=-1)
            return dp[idx][lane];
        
        
        if(nums[idx+1]!=lane)
            return dp[idx][lane]=minJumps(nums,idx+1,lane);
        
        int ans=INT_MAX;
        
        for(int l=1;l<=3;l++){
            if(l!=lane && nums[idx]!=l)
                ans=min(ans,minJumps(nums,idx,l));     
        }
         
        return dp[idx][lane]=ans+1;
    }
    
    
    int minSideJumps(vector<int>& obstacles) {
        
        int n=obstacles.size();
        
        dp.resize(n+1,vector<int>(4,-1));
        
        return minJumps(obstacles,0,2);
    }
};
