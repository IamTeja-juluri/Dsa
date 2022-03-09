class Solution {
public:
    int longestMountain(vector<int>&nums) {
     
        int n=nums.size();
        
        if(n<3) return 0;
        
        int ans=0;
        
        for(int i=1;i<n-1;i++){
            
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                
                int l=i,r=i;
                
                while(l>=1 && nums[l]>nums[l-1])
                    l--;
                
                while(r<(n-1) && nums[r]>nums[r+1])
                    r++;
                
                ans=max(ans,r-l+1);
            }
            
            
        }
        
        return ans;
    }
};
