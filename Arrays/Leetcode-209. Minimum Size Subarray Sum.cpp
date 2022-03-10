class Solution {
public:
   
    
    int minSubArrayLen(int target, vector<int>& nums) {
        
       int n=nums.size();
        
       int sum=0;
       int idx=0;
       int minlen=INT_MAX;
        
       for(int i=0;i<n;i++){
          sum+=nums[i];
          while(sum>=target){
              minlen=min(minlen,i-idx+1);
              sum=sum-nums[idx];
              idx++;
          } 
       } 
        
       return minlen==INT_MAX?0:minlen;
      
    }
};
