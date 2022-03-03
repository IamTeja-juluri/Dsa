//Soln-dfs
class Solution {
public:
    
      vector<bool> visited;
      bool cycle=false;

      bool dfs(int node,int par,vector<int> gr[]){
        
        visited[node]=true;

        for(auto nbr:gr[node]){
            
            if(!visited[nbr]){
                bool nbrfound=dfs(nbr,node,gr);
                if(nbrfound){
                    return true;
                }
            }
            else if(nbr!=par){
                cycle=true;
                return true;
            }

        }

        return false;

      }


    bool validTree(int n, vector<vector<int>> &edges) { 

      int m=edges.size();

      if(n==1 && m==0){
          return true;
      }

      if(n>1 && m==0){
          return false;
      }

      vector<int> gr[n];
        
      for(int i=0;i<n;i++){
          visited.push_back(false);
      }


      for(int i=0;i<m;i++){
           int x=edges[i][0];
           int y=edges[i][1];
           gr[x].push_back(y);
           gr[y].push_back(x);
      }
        
        dfs(0,-1,gr);

       for(int i=0;i<n;i++){
           if(visited[i]==false){
               return false;
           }
       }      
       
      return (!cycle);
      
    }
};

//Soln-Dsu
class Graph{
   
   int v;
   int *parent;
   int *rank;

   public:

   Graph(int v){

       this->v=v;
       parent=new int[v];
       rank=new int[v];

       for(int i=0;i<v;i++){
           parent[i]=-1;
           rank[i]=1;
       }
       
        
   }

     int findset(int i){

        if(parent[i]==-1){
          return i;
        }

         return parent[i]=findset(parent[i]);
       }  


       bool containsCycle(vector<vector<int> > &edges){

           int count=0;

           for(auto edge:edges){
              
              int i=edge[0];
              int j=edge[1];

              int s1=findset(i);
              int s2=findset(j);

              if(s1!=s2){
                  if(rank[s1]<rank[s2]){
                      parent[s1]=s2;
                      rank[s2]+=rank[s1];
                  }
                  else{
                      parent[s2]=s1;
                      rank[s1]+=rank[s2];
                  }
                   
              }

              else{
                  return false;
              }
   
           }

           for(int i=0;i<v;i++){
               if(parent[i]==-1){
                   count+=1;
               }
           }

           if(count>1){
               return false;
           }

           return true;

        
       }

};


class Solution {
public:

    bool validTree(int n, vector<vector<int>> &edges) {    

      Graph g(n);
      return  g.containsCycle(edges);
     
    }
};