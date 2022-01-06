//Approach 1-Using dfs

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
   
   bool dfs(int node,int parent,vector<int>adj[],vector<bool>&visited){
       
       visited[node]=true;
       
       for(auto nbr:adj[node]){
           
           if(!visited[nbr]){
               
               bool subprob=dfs(nbr,node,adj,visited);
               
               if(subprob){
                   return true;
               }
               
           }
           else if(parent!=nbr){
               return true;
           }
           
       }
      
      return false;
       
   }
    
    
    
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<bool>visited(v,false);
        
        for(int i=0;i<v;i++){
         
            if(!visited[i] && dfs(i,-1,adj,visited))
             return true;
         
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends


//Approach 2-Using Bfs
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph 
    bool bfs(int src,int v,vector<int>adj[],vector<bool>&visited){
        
       
        vector<int> parent(v,-1);
        
        queue<int> q;
        q.push(src);
        visited[src]=true;
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            for(auto nbr:adj[node]){
                
                if(visited[nbr]==false){
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=node;
                }
                else if(parent[node]!=nbr){
                    return true;
                }
                
            }
            
            
        }
        
        return false;
        
    }
    
    
    
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<bool>visited(v,false);
        
        for(int i=0;i<v;i++){
         
            if(!visited[i] && bfs(i,v,adj,visited))
             return true;
         
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
