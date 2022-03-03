class Solution {
public:
    
    void permutations(int l,int r,vector<int> &nums,vector<vector<int> > &res){
        
        if(l==r){
            res.push_back(nums);
            return;
        }
        
        
        for(int i=l;i<=r;i++){
             
            swap(nums[l],nums[i]);
            permutations(l+1,r,nums,res);
            swap(nums[l],nums[i]);
        }
        
        return;
        
    }
        
    
    vector<vector<int>> permute(vector<int>& nums) {
         
        int n=nums.size();
        
        vector<vector<int> > res;
        
         permutations(0,n-1,nums,res);
        
        return res;
        
    }
};
