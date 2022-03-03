class Solution {
public:
    unordered_map<int,int> memo;
    
    bool subsetSum(vector<int>&nums,int s,int target,int k,int i,int visited){
        
        if(k==0){
            
            return true;
        }
        
        if(s==target){
            if(memo.count(visited)>0){
                return false;
            }
            memo[visited]=1;
            return subsetSum(nums,0,target,k-1,0,visited);
        }
        
        for(int j=i;j<nums.size();j++){
            
           if( (visited>>j)&1==1  || s+nums[j]>target )
               continue;
            
            visited=visited|(1<<j);
            bool res=subsetSum(nums,s+nums[j],target,k,j+1,visited);
            if(res) return true;
            visited=visited^(1<<j);
            
        }
        
        return false;
        
    }
    
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        int s=0;
        
        for(auto x:nums){
            s+=x;
        }
        
        if((s%k)!=0) return false;
        
        return subsetSum(nums,0,s/k,k,0,0);
        
    }
};