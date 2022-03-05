class Graph{
    
    public:
    
    int v;
    list<int> *l;
    
    Graph(int v){
        this->v=v;
        l=new list<int> [v];
    }
    
    void addEdge(int x,int y){
        l[x].push_back(y);
    }
    
    bool containsCycleHelper(int node,vector<bool> &visited,vector<bool>&stack){
        
        visited[node]=true;
        stack[node]=true;
        
        for(int nbr:l[node]){
            
           if(visited[nbr]==false){
               
              bool nbrFoundCycle=containsCycleHelper(nbr,visited,stack);
               
                if(nbrFoundCycle)
                    return true;
                
            }
            
            else if(stack[nbr]==true){
                return true;
            }
            
            
        }
        
        stack[node]=false;
        return false;
        
        
    }
    
    
    bool containsCycle(){
        
        vector<bool> visited(v,false);
        vector<bool> stack(v,false);
        
        for(int i=0;i<v;i++){
            
            if(visited[i]==false){
            bool flag=containsCycleHelper(i,visited,stack);
                
            if(flag==true)
              return flag;
                
            }
            
        }
        
        return false;
        
    } 
    
    
};

class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prq) {
      
        Graph g(numCourses);
        bool res=false;
        
        for(int i=0;i<prq.size();i++){
            
           int u=prq[i][0];
           int v=prq[i][1]; 
           g.addEdge(u,v);
            
        }
        
        res=g.containsCycle();
        
        return !res;
        
    }
};
