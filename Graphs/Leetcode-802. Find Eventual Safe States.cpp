//cycle detection
// all nodes which are a part of cylce are not safe
class Solution {
public:
    
    vector<bool>visited,stack,cycle;
    
    bool dfs(int node,vector<int> adj[]){
        
        visited[node]=true;
        stack[node]=true;
        
        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                bool nbrfound=dfs(nbr,adj);
                if(nbrfound)
                    return cycle[node]=true;
            }
            else if(stack[nbr]){
                return cycle[node]=true;
            }
        }
        
        stack[node]=false;
        return false;
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
           
           int n=graph.size();
           vector<int> adj[n];
        
           for(int i=0;i<n;i++){
               for(int j=0;j<graph[i].size();j++)
                   adj[i].push_back(graph[i][j]);
           }
        
           visited.resize(n,false);
           stack.resize(n,false);
           cycle.resize(n,false);
            
           for(int i=0;i<n;i++){
               if(!visited[i])
                 dfs(i,adj);
           }
          
          vector<int> ans;
        
          for(int i=0;i<n;i++){
              if(!cycle[i])
                  ans.push_back(i);
          }
          
        
         return ans;
    }
};

//app2 
// Idea here is to reverse direction of all edges. And then perform simple topo sort.

// This is because we need to start from nodes with outdegree = 0 (Terminal Nodes), and then move backwards to find safe nodes.
// We cannot do move do backward BFS, due to which we need to reverse edges.
// So, outdegree becomes indegree , and we can easily do topo sort using this.
// Reversing edges will help us in classifying TERMINAL NODES => indegree is zero,

// and all safe nodes i.e nodes reachable from terminal nodes, that are not in a cycle.

// Also, doing topo sort will exclude all nodes that are present in a cyclic path.

// So, topo sort will give us the all nodes that are either terminal or there is a path to terminal nodes.
class Solution {
public:
    
   
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
           
           int n=graph.size();
           vector<int> adj[n];
          vector<int> outdegree(n,0);
          vector<int> ans;
          queue<int>q;
           for(int i=0;i<n;i++){
               for(int j=0;j<graph[i].size();j++){
                   adj[graph[i][j]].push_back(i);
                   outdegree[i]+=1;
               }
           }
        
          for(int i=0;i<n;i++)
              if(outdegree[i]==0)
                  q.push(i);
         
        
        while(!q.empty()){
            
            int node=q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto nbr:adj[node]){
                outdegree[nbr]-=1;
                if(outdegree[nbr]==0)
                    q.push(nbr);
            }
            
        }
        
        sort(ans.begin(),ans.end());
        
         return ans;
    }
};
