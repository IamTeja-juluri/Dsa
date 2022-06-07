class Solution {
    public int countElements(int[] nums) {
        
        Arrays.sort(nums);
        int n=nums.length;
        int cnt=0;
        
        int minarr[]=new int[n];
        int maxarr[]=new int[n];
        
        int minVal=Integer.MAX_VALUE;
        int maxVal=Integer.MIN_VALUE;
        
        for(int i=0;i<n;i++){
            minVal=Math.min(nums[i],minVal);  
            maxVal=Math.max(nums[i],maxVal);
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]>minVal && nums[i]<maxVal)
                cnt+=1;
        }
        
        return cnt;
    }
}
