class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n=nums.size();
        int ans=0;
        int count=0;
        
        int i=0;
        
        while(i<n){
            while(i<n && nums[i]==1){
                count++;
                i++;
            }
            ans=max(ans,count);
            count=0;
            while(i<n && nums[i]==0)
                i++;
        }
        
        return ans;
    }
};
