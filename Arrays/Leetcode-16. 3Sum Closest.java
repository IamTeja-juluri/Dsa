class Solution {
    public int threeSumClosest(int[] nums, int target) {
     
        int n=nums.length;
        Arrays.sort(nums);
        
        int ans=nums[0]+nums[n-2]+nums[n-1]; //take any triplet just for comparison
        
        for(int i=0;i<(n-2);i++){
            
            int low=i+1;
            int high=n-1;
            
            while(low<high){
                
                int currSum=nums[i]+nums[low]+nums[high];
                if(currSum<target)
                    low+=1;
                else
                    high-=1;
                
                if(Math.abs(target-currSum)<Math.abs(target-ans))
                    ans=currSum;
            }
            
        }
        
        
        return ans;
        
    }
}
