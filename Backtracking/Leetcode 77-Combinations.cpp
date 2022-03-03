class Solution {
public:
    
    void combinations(int n,int k,vector<vector<int> > &res,vector<int>&v){
        
        if(n==0 && k!=0){
            return;
        }
        
        if(k==0){
            res.push_back(v);
            return;
        }
        
        v.push_back(n);
        combinations(n-1,k-1,res,v);
        v.pop_back();
        combinations(n-1,k,res,v);
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int> > res;
        vector<int> v;
        
        combinations(n,k,res,v);
        
        return res;
    }
};
