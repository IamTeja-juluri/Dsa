class Solution {
public:
    //just reverse/remove/cnt the forward edges since they r the min edges to be reversed
    int minReorder(int n, vector<vector<int>>& con) {
        
        set<vector<int> > st;
        
        for(auto x:con)
            st.insert(x);
        
        vector<vector<int> > adj(n);
        
        for(auto x:con){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        queue<int> q;
        q.push(0);
        vector<bool>visited(n,false);
        visited[0]=true;
        int cnt=0;
        
        while(!q.empty()){
            int src=q.front();
            q.pop();
            for(auto nbr:adj[src]){
                if(!visited[nbr]){
                    if(st.find({src,nbr})!=st.end())
                        cnt+=1;
                    visited[nbr]=true;
                    q.push(nbr);
                }
            }
        }
            
        return cnt;
        
        
    }
};
