class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        
        double ans=0,res=INT_MIN;
        
        for(int i=0;i<k;i++)
            ans+=nums[i];
        
        res=max(ans/k,res);
        
        for(int i=0,j=k;j<n;j++,i++){
            ans=ans-nums[i]+nums[j];
            res=max(ans/k,res);
        }
        
        return res;
        
    }
};
