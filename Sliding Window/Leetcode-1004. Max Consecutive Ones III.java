class Solution {
    public int longestOnes(int[] nums, int k) {
        
        int i=0,j=0;
        int n=nums.length;
        int ans=0;
        int zerocnt=0;
        
        while(j<n){
            
            if(nums[j]==0)
                zerocnt+=1;
            if(zerocnt<=k)
                ans=Math.max(ans,j-i+1);
            else if(zerocnt>k){
                while(zerocnt>k){
                    if(nums[i]==0)
                        zerocnt-=1;
                    i+=1;
                }
            }
            j+=1;
        }
        
        
        return ans;
        
    }
}
