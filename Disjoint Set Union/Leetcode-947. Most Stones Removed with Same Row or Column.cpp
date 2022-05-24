//soln1
class Dsu{
    
    public:
    int *parent;
    int *rank;
    int n;
    
    Dsu(int v){
        n=v;
        parent=new int[n];
        rank=new int[n];
        for(int i=0;i<n;i++){
            rank[i]=1;
            parent[i]=-1;
        }
    }
    
  int find(int i){
      
      if(parent[i]==-1)
          return i;
      return parent[i]=find(parent[i]);
      
  }
    
  void unite(int x,int y){
      
      int s1=find(x);
      int s2=find(y);
      
      if(s1==s2)
          return;
      
       if(rank[s1]<rank[s2]){
              rank[s2]+=rank[s1];
              parent[s1]=s2;
          }
      else{
              rank[s1]+=rank[s2];
              parent[s2]=s1;
          }
      
      return;
      
  }  
   
    int countComp(){
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(parent[i]==-1)
                cnt+=rank[i]-1;
        }
        return  cnt;
        
    }
    
    
    
};

//soln2
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
       
        int n1=stones.size();
        
        Dsu s(n1);
        
        
        for(int i=0;i<n1;i++){
            for(int j=i+1;j<n1;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                    s.unite(i,j);
            }
        }
        
        int comp=s.countComp();
        return comp;
        
    }
};
class Dsu{
    
    public:
    int *parent;
    int *rank;
    int n;
    
    Dsu(int v){
        n=v;
        parent=new int[n];
        rank=new int[n];
        for(int i=0;i<n;i++){
            rank[i]=1;
            parent[i]=-1;
        }
    }
    
  int find(int i){
      
      if(parent[i]==-1)
          return i;
      return parent[i]=find(parent[i]);
      
  }
    
  void unite(int x,int y){
      
      int s1=find(x);
      int s2=find(y);
      
      if(s1==s2)
          return;
      
       if(rank[s1]<rank[s2]){
              rank[s2]+=rank[s1];
              parent[s1]=s2;
          }
      else{
              rank[s1]+=rank[s2];
              parent[s2]=s1;
          }
      
      return;
      
  }  
   
    int countComp(){
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(parent[i]==-1)
                cnt+=1;
        }
        return  cnt;
        
    }
    
    
    
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
       
        int n1=stones.size();
        
        Dsu s(n1);
        
        
        for(int i=0;i<n1;i++){
            for(int j=i+1;j<n1;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                    s.unite(i,j);
            }
        }
        
        int comp=s.countComp();
        return n1-comp;
        
    }
};
