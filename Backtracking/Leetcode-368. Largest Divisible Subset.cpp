class Solution {
public:
    vector<int> res,dp;
    
    void subsets(vector<int>&nums,vector<int>&v,int prev,int idx){
        
        if(idx==nums.size()){
            if(res.size()<v.size()){
                res.clear();
                res=v;
            }
            return;
        }
        
        int n=v.size();
         
        if(n>dp[idx] && nums[idx]%prev==0){
            dp[idx]=n;
            v.push_back(nums[idx]);
            subsets(nums,v,nums[idx],idx+1);
            v.pop_back();
        }
        
        subsets(nums,v,prev,idx+1);
    }
    
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        dp.resize(n+1,-1);
        sort(nums.begin(),nums.end());
        vector<int>v;
        
        subsets(nums,v,1,0);
        
        return res;
        
    }
};
