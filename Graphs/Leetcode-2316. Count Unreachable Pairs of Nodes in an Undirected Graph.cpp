class Dsu{
    
  public:
  int *parent;
  int *rank;
  int v;
    
  Dsu(int n){
      v=n;
      parent=new int[n];
      rank=new int[n];
      for(int i=0;i<n;i++){
          parent[i]=-1;
          rank[i]=1;
      }
  }  
    
  int find(int i){
      if(parent[i]==-1)
          return i;
      return parent[i]=find(parent[i]);
  }  
    
  void unite(int a,int b){
      
      int s1=find(a);
      int s2=find(b);
      
      if(s1!=s2){
          if(rank[s1]<rank[s2]){
              rank[s2]+=rank[s1];
              parent[s1]=s2;
          }
          else{
              rank[s1]+=rank[s2];
              parent[s2]=s1;
          }
      }
      
      return;
  } 
    

    long long countComponents(){
        
        vector<int> vec;
        
        for(int i=0;i<v;i++){
            if(parent[i]==-1)
                vec.push_back(rank[i]);
        }
        

        int n=vec.size();
        
        long long cnt = 0 ;
        long long sum = accumulate(vec.begin(),vec.end(),0) ;
 
        for(int i=0;i<n;i++){
            sum=(long long)sum-(long long)vec[i];
            cnt+= (long long)(vec[i]*(long long)(sum));
        }
        
        return cnt;
    }
    
};


class Solution {
public:

    
    long long countPairs(int n, vector<vector<int>>& edges) {
     
        Dsu s(n);
        
        for(auto x:edges){
            int first=x[0];
            int second=x[1];
            s.unite(first,second);
        }
     
        
        return s.countComponents();
    }
};
