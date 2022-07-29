class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        long long j=0,i=0;
        int n=nums.size();
        long long sum=0;
        
        long long ans=0;
        sort(nums.begin(),nums.end());
        
        for(;i<n;i++){
            sum+=nums[i];
            while((nums[i]*(i-j+1))>(sum+k)){
                sum-=nums[j];
                j+=1;
            }
            ans=max(ans,i-j+1);
        }
        
        return ans;
    }
};
