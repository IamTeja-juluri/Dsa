//kruskals algo
class DSU{
  public:
    
    int *parent;
    int *rank;
    
    DSU(int v){
        
        parent=new int[v];
        rank=new int[v];
        
        for(int i=0;i<v;i++){
            parent[i]=-1;
            rank[i]=1;
        }
    }
    
    int find(int i){
        if(parent[i]==-1)
            return i;
        return parent[i]=find(parent[i]);
    }
    
    void unite(int x,int y,int s1,int s2){
    
        
            if(rank[s1]<rank[s2]){
                rank[s2]+=rank[s1];
                parent[s1]=s2;
            }
            else{
                rank[s1]+=rank[s2];
                parent[s2]=s1;
            }
  
      }
    
};


class Solution {
public:
    
    //take pairs instead of vector as pairs are fast 
    vector<pair<int,pair<int,int> > >edgelist;
     
    int manhattan(vector<int>&b,vector<int>&a){
        
        int dist=abs(b[0]-a[0])+abs(b[1]-a[1]);
        return dist;
        
    }
    

      int kruskals(int n){
          
        DSU s(n);
        
        int mincost=0;
        sort(edgelist.begin(),edgelist.end());
        
        for(auto edge:edgelist){
            
            int wt=edge.first;
            int x=edge.second.first;
            int y=edge.second.second;
            
            int s1=s.find(x);
            int s2=s.find(y);
            
            if(s1!=s2){
                mincost+=wt;
                s.unite(x,y,s1,s2);
            }
            
        } 
        
        return mincost;
    }
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int manhattan_dist=manhattan(points[j],points[i]);
                edgelist.push_back({manhattan_dist,{i,j}});
            }
        }
    
        return kruskals(n);
    }
};
//prims algo
class Solution {
public:
    
    vector<pair<int,int> >*l;
    
  
     int manhattan(vector<int>&b,vector<int>&a){
        
        int dist=abs(b[0]-a[0])+abs(b[1]-a[1]);
        return dist;
        
    }
    
    
    void addEdge(int x,int y,int wt){
        l[x].push_back({y,wt});
        l[y].push_back({x,wt});
    }
    
    
    int prims(int n){
        
        
      priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
      
      bool *visited=new bool[n]{false};  
      int mincost=0;
      
      pq.push({0,0});
        
        while(!pq.empty()){
            
            auto curr=pq.top();
            pq.pop();
            
            int dest=curr.second;
            int weight=curr.first;
            
            if(visited[dest]==true)
                continue;
            
            visited[dest]=true;
            mincost+=weight;
            
            for(auto nbr:l[dest]){
                if(visited[nbr.first]==false){
                    pq.push({nbr.second,nbr.first});
                }
            }
            
            
        }
        
        return mincost;
    }
    
    
   
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        
        l=new vector<pair<int,int>>[n];  
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int manhattan_dist=manhattan(points[j],points[i]);
                addEdge(i,j,manhattan_dist);
            }
        }
    
        return prims(n);
    }
};
