class Solution {
    public int maxScore(int[] nums, int k) {
        
        int n=nums.length;
        
        int[] pref=new int[n+1];
        int[] suff=new int[n+1];
        
        int ans=0;
        
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pref[i+1]=sum;
        }
        
        sum=0;
        
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            suff[i]=sum;
        }
        
        
        for(int i=0;i<=k;i++){
            
            int sum1=pref[i];
            int sum2=suff[n-k+i];
            ans=Math.max(ans,sum1+sum2);
            
        }
        
        
        return ans;
    }
}
