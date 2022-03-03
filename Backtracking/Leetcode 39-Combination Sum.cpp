class Solution {
public:
    
    void targetsum(vector<int> &candidates,vector<int> &v,int n,int target,vector<vector<int> > &res){
        
         if(n==-1){
            return;
        }
        
        if(target==0){
            res.push_back(v);
            return;
        }
        
        
        if(candidates[n]<=target){
            v.push_back(candidates[n]);
            targetsum(candidates,v,n,target-candidates[n],res); //inclusive
            v.pop_back();
        }
        
        targetsum(candidates,v,n-1,target,res);    //exclusive
        return;
        
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n=candidates.size();
        vector<vector<int> > res;
        vector<int> v;
        targetsum(candidates,v,n-1,target,res);
        
        return res;
    }
};
