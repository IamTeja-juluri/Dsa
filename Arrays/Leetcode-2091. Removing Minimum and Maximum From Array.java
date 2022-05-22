class Solution {
    public int minimumDeletions(int[] nums) {
        
        int n=nums.length;
        
        if(n==1)
            return 1;
        
        int mini=Integer.MAX_VALUE;
        int maxi=Integer.MIN_VALUE;
        
        for(int i=0;i<n;i++){
            mini=Math.min(nums[i],mini);
            maxi=Math.max(nums[i],maxi);
        }
        
        int minidx=-1;
        int maxidx=-1;
        
        for(int i=0;i<n;i++){
            if(mini==nums[i])
                minidx=i;
            if(maxi==nums[i])
                maxidx=i;   
        }
        
       int left=Math.min(minidx,maxidx);
       int right=Math.max(minidx,maxidx);
        
       int leftsize=left+1;
       int rightsize=n-right;
        
       int op1=leftsize+rightsize;
       int op2=right+1;
       int op3=n-left; 
        
       int ans1=Math.min(op1,op2);
       int ans2=Math.min(ans1,op3);
        
        return ans2;
    }
}
