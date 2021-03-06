https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    vector<vector<int> >res;
    set<vector<int> >st;
    
    void subsets(vector<int>&nums,vector<int>&v,int idx){
        
        if(idx==nums.size()){
            st.insert(v);
            return;
        }
        
        v.push_back(nums[idx]);
        subsets(nums,v,idx+1);
        v.pop_back();
        subsets(nums,v,idx+1);
    
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            vector<int> v;
            subsets(nums,v,i);
        }
        
        for(auto x:st)
            res.push_back(x);
    
        return res;
    }
};
//Better app -No need of set since we ve sorted array already
class Solution {
public:
    
    vector<vector<int> >res;
    
    void subsets(vector<int>&nums,vector<int>&v,int idx){
        
        if(idx==nums.size()){
           res.push_back(v);
            return;
        }
        
        v.push_back(nums[idx]);
        subsets(nums,v,idx+1);
        v.pop_back();
        
        while(idx+1<nums.size() and nums[idx]==nums[idx+1]) idx++;
        
        subsets(nums,v,idx+1);
    
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
     
        vector<int> v;
        subsets(nums,v,0);

    
        return res;
    }
};

