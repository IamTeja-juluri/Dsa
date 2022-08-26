class Solution {
public:
    
    bool increasingTriplet(vector<int>& nums) {
        
       int n=nums.size();
        
      vector<int> leftmin(n),rightmax(n);
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            leftmin[i]=mini;
        }
        
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,nums[i]);
            rightmax[i]=maxi;
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]>leftmin[i] and nums[i]<rightmax[i])
                return true;
        }
        
      
        return false;
    }
};
