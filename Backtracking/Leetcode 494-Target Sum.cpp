//BackTracking

class Solution {
public:
    
    void totalways(vector<int>&nums,int i,int sum,int &target,int &ans){
        
        if(i==nums.size()){
            if(sum==target){
                 ans+=1;
            }
            return ;
        }
        
        
     totalways(nums,i+1,sum+nums[i],target,ans);
     totalways(nums,i+1,sum-nums[i],target,ans);
        
        
    }
    
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int ans=0;
        totalways(nums,0,0,target,ans);
        return ans;
        
    }
};

//Simple Recursion


class Solution {
public:
    
    int totalways(vector<int>&nums,int i,int sum,int &target){
        
        if(i==nums.size()){
            if(sum==target){
                return 1;
            }
            return 0;
        }
        
        
        return totalways(nums,i+1,sum+nums[i],target)+totalways(nums,i+1,sum-nums[i],target);
        
        
    }
    
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return totalways(nums,0,0,target);
        
    }
};
