class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& vec) {
     
        vector<vector<int> > res;
        
        sort(vec.begin(),vec.end());
        
        res.push_back(vec[0]);
        int n=vec.size();
        int j=0;
        
        for(int i=1;i<n;i++){
       
            if(vec[i][0]<=res[j][1])
                res[j][1]=max(res[j][1],vec[i][1]);
            else{
                res.push_back(vec[i]);
                j+=1;
            }
        }
       
        
        return res;
    }
};

