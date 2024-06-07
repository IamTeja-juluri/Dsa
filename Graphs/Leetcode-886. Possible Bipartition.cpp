// using dsu

class Dsu{
    public :
    int * parent;
    int * rank;
    int v;
    Dsu(int n){
        v=n;
        parent = new int[v+1];
        rank = new int[v+1];
        for(int i=0;i<=v;i++){
            rank[i]=1;
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }

    void unite(int x,int y){
        int s1 = findParent(x);
        int s2 = findParent(y);
        if(s1 == s2){
            return ;
        }

        if(rank[s1]<rank[s2]){
            parent[s1]=s2;
            rank[s2]+=rank[s1];
        }else{
            parent[s2]=s1;
            rank[s1]+=rank[s2];
        }
    }

};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        if(n==1)
            return true;
            
        Dsu s(n);
        vector<int> adj[n+1];

        for(auto x:dislikes){
            int first = x[0];
            int second = x[1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }

        for(int i=1;i<=n;i++){
            if (adj[i].empty()) continue;
            int first = adj[i][0];
            for(int j=1;j<adj[i].size();j++){
                s.unite(first,adj[i][j]);
                // if(res == false)
                //     return res;
            }

        }

        for(auto x: dislikes){
            int first = x[0];
            int second = x[1];
            int parent1= s.findParent(first);
            int parent2= s.findParent(second);
            if(parent1 == parent2)
                return false;
        }

        return true;

    }
};




// using coloring
class Solution {
public:
    
    bool dfs(int node,int par,int col,vector<int> &color,vector<int> gr[]){
        
        color[node]=col;
        
        for(auto nbr:gr[node]){
            
            if(!color[nbr] ){
                bool subprob=dfs(nbr,node,3-col,color,gr);
                if(!subprob) 
                    return false;
            }
            else if( nbr!=par && col==color[nbr]){
                     return false;
            }
        }
        
        return true;
        
    }
    
    
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        
        vector<int> color(n,0);
        vector<int> gr[n];
        
        for(int i=0;i<d.size();i++){
              int x=d[i][0]-1;
              int y=d[i][1]-1;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
        
        for(int i=0;i<n;i++){
            
            if(color[i]==0){
            bool ans=dfs(i,-1,1,color,gr);
         
            if(ans==false){
                return false;
            }
                
          }        
            
        }
        
        return true;
        
    }
};
