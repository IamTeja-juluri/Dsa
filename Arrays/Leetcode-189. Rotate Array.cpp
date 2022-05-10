class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
            
          if(k>=n) 
            k=k%n;
        
        vector<int> res;
        
        int idx=n-k;
        
        while(idx<n){
            res.push_back(nums[idx]);
            idx+=1;
        }
        
        idx=0;
        int end=n-k;
        
        while(idx<end){
            res.push_back(nums[idx]);
            idx+=1;
        }
        
        int i=0;
        
        for(auto x:res){
            nums[i]=x;
            i+=1;
        }
        
    }
};
