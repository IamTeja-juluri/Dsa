//We just have to count the number of vertices which have zero incoming edges
//Because thats the only node it can reach itself
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
     
        vector<int> ans;
        
        if(n==0)
            return ans;
        
        vector<int>count(n,0);
        
        for(auto edge:edges)
            count[edge[1]]+=1;
        
        for(int i=0;i<n;i++){
            if(count[i]==0)
                ans.push_back(i);
        }
        
        
        return ans;
        
    }
};
