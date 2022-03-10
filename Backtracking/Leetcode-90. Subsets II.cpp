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
