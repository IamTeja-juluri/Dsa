class Solution {
    public int numOfSubarrays(int[] nums, int k, int t) {
        
        
        int n=nums.length;
         
        int cnt=0;
        int s=0;
        
        for(int i=0;i<k;i++)
            s+=nums[i];
        
        if((s/k)>=t)
            cnt+=1;
        
        
        for(int i=0,j=k;j<n;j++,i++){
            s-=nums[i];
            s+=nums[j];
            if((s/k)>=t)
                cnt+=1;
        }
        
        
        return cnt;
    }
}
