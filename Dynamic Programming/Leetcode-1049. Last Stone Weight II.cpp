class Solution {
public:
    
    map<pair<int,int>,int> dp;
    
    int minSubsetSum(vector<int>&nums,int idx,int sum){
        
        if(idx==nums.size()){
            if(sum<0)
                return INT_MAX;
            return sum;
        }
        
        if(dp.find({idx,sum})!=dp.end())
            return dp[{idx,sum}];
        
        return dp[{idx,sum}]=min(minSubsetSum(nums,idx+1,sum+nums[idx]),minSubsetSum(nums,idx+1,sum-nums[idx]));
     
    }
    

    int lastStoneWeightII(vector<int>& stones) {
        
        
        return minSubsetSum(stones,0,0);
        
    }
};
