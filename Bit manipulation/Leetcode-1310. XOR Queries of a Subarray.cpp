class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int> ans;
        vector<int> prf;
        
        prf.push_back(arr[0]);
        
        for(int i=1;i<arr.size();i++)
            prf.push_back(prf[i-1]^arr[i]);
        
        
        for(int i=0;i<queries.size();i++){
            
            if(queries[i][0]==0)
                ans.push_back(prf[queries[i][1]]);
            else
                ans.push_back( prf[queries[i][1]]^prf[queries[i][0]-1]);
            
        }
        
        return ans;
    }
};
