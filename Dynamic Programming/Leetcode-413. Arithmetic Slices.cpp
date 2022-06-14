class Solution {
public:
    
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size();
        if(n<3)
            return 0;
        
        int prevdiff=nums[1]-nums[0];
        int cnt=0;
        int ans=0;
        
        for(int i=1;i<(n-1);i++){
            
            int currdiff=nums[i+1]-nums[i];
            if(currdiff==prevdiff)
                cnt+=1;
            else{
                cnt=0;
                prevdiff=currdiff;
            }
            
            ans+=cnt;
        }
        
        
        return ans;
    }
};
