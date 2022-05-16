class Solution {
public:
    
    int largestCombination(vector<int>&nums) {
       
         
        int ans=0;
            
        for(int i=30;i>=0;i--){
            int cnt=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]&(1<<i))
                    cnt+=1;
            }
            ans=max(ans,cnt);
        }
          
        return ans;
       
    }
};
