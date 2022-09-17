//use kadanes algo for min sum and max sum and take abs of max of both
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int meh=nums[0];
        int msf=nums[0];
        
        int n=nums.size();
        
        for(int i=1;i<n;i++){
            meh+=nums[i];
            if(meh<nums[i])
                meh=nums[i];
            if(msf<meh)
                msf=meh;
        }
        
        int min_eh=nums[0];
        int min_sf=nums[0];
        
        for(int i=1;i<n;i++){
            min_eh+=nums[i];
            if(min_eh>nums[i])
                min_eh=nums[i];
            if(min_sf>min_eh)
                min_sf=min_eh;
        }
        
        return max(abs(msf),abs(min_sf));
        
    }
};
