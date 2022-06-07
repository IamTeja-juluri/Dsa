class Solution {
    
    public int maxSubarraySum(int[] nums){
        
        int currSum=nums[0];
        int resSum=nums[0];
        
        int n=nums.length;
        
        for(int i=1;i<n;i++){
            currSum+=nums[i];
            if(currSum<nums[i])
                currSum=nums[i];
            if(resSum<currSum)
                resSum=currSum;
        }
        
        return resSum;
    }
    
    public int minSubarraySum(int[] nums){
        
        int currSum=nums[0];
        int resSum=nums[0];
        
        int n=nums.length;
        
        for(int i=1;i<n;i++){
            currSum+=nums[i];
            if(currSum>nums[i])
                currSum=nums[i];
            if(resSum>currSum)
                resSum=currSum;
        }
        
        return resSum;
    }
    
    
    public int maxSubarraySumCircular(int[] nums) {
        
        int total_sum=0;
        int n=nums.length;
        int maxVal=Integer.MIN_VALUE;
        boolean foundPositive=false;
        
        //border Case because if all elements are negative we have to return maximum of array
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
            if(nums[i]>=0)
            foundPositive=true;
            maxVal=Math.max(maxVal,nums[i]);
        }
        
        if(foundPositive==false)
            return maxVal;
       
        int op1=maxSubarraySum(nums); //Assuming sum is in nonWrapped part
        int op2=total_sum-minSubarraySum(nums); //Assuming sum is in wrapped part so  we r finding minimum subarray sum
        
        int ans=Math.max(op1,op2);
        
        return ans;
    }
}
