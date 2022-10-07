class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& rest) {
     
        unordered_set<int> st;
        
        for(auto x:rest)
            st.insert(x);
        
        vector<vector<int> >adj(n);
        
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(0);
        visited[0]=true;
        int cnt=1;
        
        while(!q.empty()){
            int src=q.front();
            q.pop();
            for(auto nbr:adj[src]){
                if(!visited[nbr] and st.find(nbr)==st.end()){
                    // cout<<src<<"->"<<nbr<<endl;
                    q.push(nbr);
                    visited[nbr]=true;
                    cnt+=1;
               }
            }
        }
        
        return cnt;
    }
};
