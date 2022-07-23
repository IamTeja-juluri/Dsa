//cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     
        
        int n=nums.size();
        int zeroes=0;
        int ans=0;
        int j=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                zeroes+=1;
            while(zeroes>k){
                if(nums[j]==0)
                    zeroes-=1;
                j+=1;
            }
            ans=max(i-j+1,ans);
        }
        
        
        
        return ans;
    }
};

//java
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
