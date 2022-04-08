class Solution {
public:
    
    vector<vector<int> >dp;
   
    int maxSumHelper(vector<int>&nums,int idx,int rem){
        
        if(idx==nums.size()){
            if(rem==0)
                return 0;
            return INT_MIN;
        }
        
        if(dp[idx][rem]!=-1)
            return dp[idx][rem];
      
      return  dp[idx][rem]=max(nums[idx]+maxSumHelper(nums,idx+1,(rem+nums[idx])%3),maxSumHelper(nums,idx+1,rem) );
        
    }
    
    int maxSumDivThree(vector<int>& nums) {
        
       
        int n=nums.size();
       
        dp.resize(n+1,vector<int>(4,-1));
        
        return maxSumHelper(nums,0,0);
       
    }
};
