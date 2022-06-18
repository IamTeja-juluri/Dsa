class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        int i=0;
        int j=n-1;
        int ans=INT_MIN;
        
        while(i<j){
            ans=max(ans,nums[i]+nums[j]);
            i+=1;
            j-=1;
        }
        
        return ans;
    }
};
