class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& org, int m, int n) {
        
        vector<vector<int> > ans;
       
        if(org.size()!=m*n)
            return ans;
        
        ans.resize(m,vector<int>(n,0));
        
        int p=0,q=0;
        
        for(auto x:org){
            ans[p][q++]=x;
            if(q==n){
                p+=1;
                q=0;
            }
        }
        
        
        
        return ans;
    }
};
