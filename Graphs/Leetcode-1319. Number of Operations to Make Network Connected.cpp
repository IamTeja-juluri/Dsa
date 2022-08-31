class Solution {
public:
    
    vector<bool> visited;
    
    void dfs(int src,vector<int> edges[]){
        visited[src]=true;
        for(auto nbr:edges[src]){
            if(!visited[nbr])
                dfs(nbr,edges);
        }
    }
    
    
    int makeConnected(int n, vector<vector<int>>&c) {
        
        vector<int>edges[n];
        
        for(auto x:c){
            edges[x[0]].push_back(x[1]);
            edges[x[1]].push_back(x[0]);
        }
        
        int count=0;
        visited.resize(n,false);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,edges);
                count+=1;
            }
        }
        
        int no_of_edges=c.size();
       
         int reqd=count-1;
         
        if(no_of_edges>=(n-1))
        return reqd;
        
        return -1;
    }
};
