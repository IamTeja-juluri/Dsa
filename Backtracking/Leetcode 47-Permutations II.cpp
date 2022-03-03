class Solution {
public:
    
    void permute(int l,int r,vector<int>&nums,set<vector<int> > &st){
        
        if(l==r){
            st.insert(nums);
            return;
        }
        
        for(int i=l;i<=r;i++){
            
            swap(nums[i],nums[l]);
            permute(l+1,r,nums,st);
            swap(nums[i],nums[l]);
            
        }
        
        return;
            
    }
    
     
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
         int n=nums.size();
         set<vector<int> > st;
         permute(0,n-1,nums,st);
         
        vector<vector<int> > res;
        
        for(auto x:st){
            res.push_back(x);
        }
        
        return res;
        
    }
};
