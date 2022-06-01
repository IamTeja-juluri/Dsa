class Solution {
    public int singleNumber(int[] nums) {
     
        int n=nums.length;
        int[] count=new int[32];
        
        Arrays.fill(count,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                if((nums[i]&(1<<j))!=0)
                    count[j]+=1;
            }
        }
        
        int ans=0;
        
        for(int i=0;i<32;i++){
            if((count[i]%3)!=0)
                ans=ans+(1<<i);
        }
        
        return ans;
        
    }
}
