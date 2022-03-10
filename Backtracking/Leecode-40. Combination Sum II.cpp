class Solution {
public:
    
   set<vector<int>> st;
   vector<vector<int>>res;
    
    void combinations(vector<int>&nums,vector<int>&v,int target,int idx){
        
        if(target==0){
            st.insert(v);
            return ;
        }
        
        if(idx==nums.size())
            return;
            
        if(nums[idx]<=target){
            v.push_back(nums[idx]);
            combinations(nums,v,target-nums[idx],idx+1);
            v.pop_back();
        }
        
        while(idx+1<nums.size() and nums[idx]==nums[idx+1]) idx++;
        combinations(nums,v,target,idx+1);
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
      
      int n=nums.size(); 
      sort(nums.begin(),nums.end());
          
      // for(int i=0;i<n;i++){ //this loop gives tle
      //     vector<int> v;
      //     combinations(nums,v,target,i);
      // }
        
        vector<int> v;
        combinations(nums,v,target,0);
        
      for(auto x:st)  
        res.push_back(x);
        
        return res;
    }
};
//better app without set
class Solution {
public:
    
   vector<vector<int>>res;
    
    void combinations(vector<int>&nums,vector<int>&v,int target,int idx){
        
        if(target==0){
            res.push_back(v);
            return ;
        }
        
        if(idx==nums.size())
            return;
            
        if(nums[idx]<=target){
            v.push_back(nums[idx]);
            combinations(nums,v,target-nums[idx],idx+1);
            v.pop_back();
        }
        
        while(idx+1<nums.size() and nums[idx]==nums[idx+1]) idx++;
        combinations(nums,v,target,idx+1);
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
      
      int n=nums.size(); 
      sort(nums.begin(),nums.end());
          
      vector<int> v;
      combinations(nums,v,target,0);
        
        return res;
    }
};
