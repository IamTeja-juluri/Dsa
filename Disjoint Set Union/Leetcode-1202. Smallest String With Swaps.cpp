class Dsu{
    
    public:
    int *parent;
    int *rank;
    
    Dsu(int v){
         parent=new int[v];
         rank=new int[v];
        for(int i=0;i<v;i++){
            parent[i]=-1;
            rank[i]=1;
        }
    }
    
    int findSet(int i){
        if(parent[i]==-1)
            return i;
        return parent[i]=findSet(parent[i]);
    }
    
    void unite(int a,int b){
          
         int s1=findSet(a);
         int s2=findSet(b);
         
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
     
    }
    
    
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n=s.size();
        Dsu so(n);
        
        for(int i=0;i<pairs.size();i++){
            int a=pairs[i][0];
            int b=pairs[i][1];
            so.unite(a,b);
        }
        
        unordered_map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++){
           int par=so.findSet(i);
           mp[par].push_back(i); 
        }
      
        string ans(n,' ');
        
        for(auto it=mp.begin();it!=mp.end();it++){
          
            vector<int> indices=it->second;
            vector<char> chararray;
            
            for(auto idx:indices)
                chararray.push_back(s[idx]);
            
            sort(chararray.begin(),chararray.end());
            int i=0;
            
            for(auto idx:indices)
                ans[idx]=chararray[i++];
                
        }
        
      return ans;
    }
};

