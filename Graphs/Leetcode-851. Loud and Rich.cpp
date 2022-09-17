class Solution {
public:
    
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        int n=quiet.size();
        
        vector<int> edgelist[n];
        vector<int> ans;
        
        for(auto x:richer)
            edgelist[x[0]].push_back(x[1]);
        
        queue<int> q;
        
        vector<int> indegree(n,0);
        
        for(int i=0;i<n;i++){
            ans.push_back(i);
            for(auto nbr:edgelist[i])
                indegree[nbr]+=1;
        }
        
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(auto nbr:edgelist[x]){
                if(quiet[ans[nbr]]>quiet[ans[x]])
                    ans[nbr]=ans[x];
                indegree[nbr]-=1;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }
      
        return ans;
    }
};
