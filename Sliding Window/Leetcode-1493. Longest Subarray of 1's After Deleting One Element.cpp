class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int ans=0;
        bool found=false;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                found=true;
                break;
            }
        }
        
        if(!found)
            return n-1;
        
        for(int i=0;i<n;i++){
            
            if(nums[i]==0){
                
                int left=i-1;
                int right=i+1;
                
                while(left>=0 && nums[left]==1)
                    left-=1;
                
                 while(right<n && nums[right]==1)
                    right+=1;
                
                ans=max(ans,right-left-2);   
            }
        }
        
        return ans;
    }
};
