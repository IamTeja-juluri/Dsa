class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        
        for(int i=0;i<mat.size();i++){
            int freq=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0)
                    break;
                freq+=1;
            }
            pq.push({freq,i});
        }
        
        vector<int> res;
        
        while(!pq.empty() && k!=0){
            k--;
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};
