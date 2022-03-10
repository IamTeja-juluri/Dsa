class Solution {
public:
    
   set<vector<int>> st;
   vector<vector<int>>res;
    
    void Subsequences(vector<int>&nums,vector<int>&v,int idx){
        
        if(idx==nums.size()){
            if(v.size()>=2){
                st.insert(v);
            }
            return;
        }
        
        int n=v.size();
        
        if(nums[idx]>=v[n-1]){
            v.push_back(nums[idx]);
            Subsequences(nums,v,idx+1);
            v.pop_back();
        }
        
        Subsequences(nums,v,idx+1);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
     
        for(int i=0;i<nums.size()-1;i++){
            vector<int> v;
            v.push_back(nums[i]);
            Subsequences(nums,v,i+1);
        }
        
        for(auto x:st)
          res.push_back(x);   
    
        return res;
    }
};
