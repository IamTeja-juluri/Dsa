class Solution {
public:
    
    bool isFound(vector<int>&nums,int target,int size){
        
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<size;i++)
            sum+=nums[i];
        
        if(sum>=target)
            return true;
        
        for(int i=1;i<=(n-size);i++){
           sum-=nums[i-1];
           sum+=nums[i+size-1];
           if(sum>=target)
               return true;
        }
        
        return false;
    }
    
    int binarySearch(int target,vector<int>&nums){
        
        int low=1,high=nums.size();
        int len=0;
      
        while(low<=high){
            
            int mid=low+(high-low)/2;
            if(isFound(nums,target,mid)){
                len=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        
        return len;
    }
    
    
    int minSubArrayLen(int target, vector<int>& nums) {
        
        return binarySearch(target,nums);
    }
};
